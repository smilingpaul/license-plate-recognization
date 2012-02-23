#include "clientInfos.h"

clientInfos::clientInfos(bool auth)
{
	this->isAuth = auth;
}

clientInfos::~clientInfos()
{
}

SOCKET			clientInfos::getSocket()
{
	return (this->soc);
}

void			clientInfos::setSocket(SOCKET socket)
{
	this->soc = socket;
}

SOCKADDR_IN		clientInfos::getAddr()
{
	return (this->addr);
}

void			clientInfos::setAddr(SOCKADDR_IN address)
{
	this->addr = address;
}

int				clientInfos::getAddrLen()
{
	return (this->addrLen);
}

void			clientInfos::setAddrLen(int len)
{
	this->addrLen = len;
}