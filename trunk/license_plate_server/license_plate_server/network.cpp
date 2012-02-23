#include "network.h"

Network::Network()
{
	WSADATA		WSAData;

	Network::port = 4242;
    WSAStartup(MAKEWORD(2,0), &WSAData);
	Network::fillSockAddr();
}

Network::~Network()
{
	WSACleanup();
}

void	Network::fillSockAddr()
{
	this->sin.sin_addr.s_addr	= INADDR_ANY;
	this->sin.sin_family		= AF_INET;
	this->sin.sin_port			= htons(this->port);

	this->sock = socket(AF_INET,SOCK_STREAM,0);
	bind(this->sock, (SOCKADDR *)&this->sin, sizeof(this->sin));
	listen(this->sock, 42);
}

SOCKET	Network::getSocket()
{
	return (this->sock);
}

void	Network::setSocket(SOCKET socket)
{
	this->sock = socket;
}

SOCKET	Network::acceptClient(clientInfos *p)
{
	int		lenTemp;
	SOCKET	cSock;

	lenTemp = p->getAddrLen();
	cSock = accept(this->sock, (SOCKADDR *) &p->getAddr(), &lenTemp);
	p->setAddrLen(lenTemp);
	return (cSock);
}
