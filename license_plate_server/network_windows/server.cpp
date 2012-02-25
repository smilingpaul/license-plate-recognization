#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>
#include "server.h"
#include "network.h"

using namespace xercesc;

Server::Server()
{
	this->pictureId = 1;
}

Server::~Server()
{

}

void		Server::start()
{
	int							clientId = 1;
	Network						nt;
	struct thread_param         params;
	SOCKET						NewConnection;

	InitializeCriticalSection(&this->cs);

	while (1)
	{
		clientInfos				*ci = new clientInfos(false);
		ci->setAddrLen(sizeof(ci->getAddr()));
		NewConnection = nt.acceptClient(ci);
		ci->setSocket(NewConnection);
		params.ser = this;
		params.soc = NewConnection;
		params.id = clientId;
		std::cout << "new client ::  IP : " << inet_ntoa(ci->getAddr().sin_addr) << " ,port = " << ntohs(ci->getAddr().sin_port) << std::endl;
		this->clientsMap.insert(std::pair<int, clientInfos*>(clientId, ci));
		clientId++;
		delete ci;
		CreateThread(NULL, 0,&Server::ThreadLauncher, &params,0,NULL);
	}
}

DWORD Server::ClientThread(SOCKET soc, int id)
{
	std::map<int, clientInfos*>::iterator	it;
	clientInfos								*ci;
	DWORD									header;

	header = 0;
	EnterCriticalSection(&this->cs);
	it = Server::clientsMap.find(id);
	ci = it->second;
	LeaveCriticalSection(&this->cs);

	while (header != QUIT_SERVER)
	{
		header = 0;
		recv(soc, reinterpret_cast<char *>(&header), sizeof(DWORD), 0);
		switch(header)
		{
			case CHECK_AUTH:
				this->checkAuth(soc, ci);
				break;
			case SEND_PICTURE:
				this->receivePicture(soc);
				break;
		}
	}

	return (0);
}

void		Server::receivePicture(SOCKET soc)
{
	int	filesize;
	filesize = 0;
	char	*id = new char[1024];
	std::string	pictureName;

	itoa(this->pictureId, id, 10);
	pictureName = id;
	pictureName += ".jpg";
	this->pictureId++;
	FILE *fw = fopen(pictureName.c_str(), "wb");
	int	nb_write = 0;

	recv(soc, reinterpret_cast<char *>(&filesize), sizeof(int), 0);

	while (filesize > 0)
	{
		char buffer[1024];

		if (filesize >= 1024)
		{
			recv(soc, buffer, 1024, 0);
			nb_write += fwrite(buffer, 1024, 1, fw);
		}
		else
		{
			recv(soc, buffer, filesize, 0 );
			nb_write += fwrite(buffer, filesize, 1, fw);
		}
		filesize -= 1024;
	}
	fclose(fw);
}

void		Server::checkAuth(SOCKET soc, clientInfos *ci)
{
	bool		isAuth = false;
	size_t		found;
	std::string	auth;
	std::string	username;
	std::string	password;

	while (isAuth == false)
	{
		auth = this->receiveLine(soc);
		found = auth.find_first_of("|");
		username = auth.substr(0, found);
		password = auth.substr((found + 1), (auth.size() - 1));
		isAuth = this->checkInXml(username, password);
		if (isAuth == false)
			send(soc, "ko\n", 3, 0);
	}
	send(soc, "ok\n", 3, 0);
	ci->isAuth = true;
}

bool		Server::checkInXml(std::string username, std::string password)
{
	XMLCh*						TAG_root;
	XMLCh*						TAG_user;
	XMLCh*						ATTR_username;
	XMLCh*						ATTR_password;
	char*						m_username;
	char*						m_password;
	xercesc::XercesDOMParser	*m_ConfigFileParser;
	std::string					configFile="user.xml";

	XMLPlatformUtils::Initialize();

	TAG_root = XMLString::transcode("root");
	TAG_user = XMLString::transcode("user");
	ATTR_username = XMLString::transcode("username");
	ATTR_password = XMLString::transcode("password");

	m_ConfigFileParser = new XercesDOMParser;
	m_ConfigFileParser->setValidationScheme(XercesDOMParser::Val_Never);
	m_ConfigFileParser->setDoNamespaces(false);
	m_ConfigFileParser->setDoSchema(false);
	m_ConfigFileParser->setLoadExternalDTD(false);
	m_ConfigFileParser->parse(configFile.c_str());
	xercesc::DOMDocument*		xmlDoc = m_ConfigFileParser->getDocument();
	DOMElement*					elementRoot = xmlDoc->getDocumentElement();
	DOMNodeList*				children = elementRoot->getChildNodes();
	const  XMLSize_t			nodeCount = children->getLength();
	
	if(!elementRoot)
		std::cout << "empty XML" << std::endl;

	for(XMLSize_t i = 0; i < nodeCount; ++i)
	{
         DOMNode* currentNode = children->item(i);
         if(currentNode->getNodeType() &&
             currentNode->getNodeType() == DOMNode::ELEMENT_NODE)
         {
            DOMElement* currentElement = dynamic_cast<xercesc::DOMElement*>(currentNode);
            if( XMLString::equals(currentElement->getTagName(), TAG_user))
            {
               const XMLCh* xmlch_username = currentElement->getAttribute(ATTR_username);
               m_username = XMLString::transcode(xmlch_username);
               const XMLCh* xmlch_password = currentElement->getAttribute(ATTR_password);
               m_password = XMLString::transcode(xmlch_password);
			   if (username.compare(m_username) == 0 && password.compare(m_password) == 0)
					return (true);
            }
         }
    }
	return (false);
}

std::string Server::receiveLine(SOCKET soc)
{
  std::string ret;
  while (1)
  {
    char r;

    switch(recv(soc, &r, 1, 0))
	{
      case 0:
        return ret;
      case -1:
        return "";
	}

	if (r == '\n')
		return ret;

    ret += r;
  }
}

