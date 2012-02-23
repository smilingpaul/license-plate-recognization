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
	this->sin.sin_addr.s_addr	= inet_addr("127.0.0.1");
	this->sin.sin_family		= AF_INET;
	this->sin.sin_port			= htons(this->port);

	this->sock = socket(AF_INET,SOCK_STREAM,0);
	connect(this->sock, (SOCKADDR *)&this->sin, sizeof(this->sin));
}

SOCKET	Network::getSocket()
{
	return (this->sock);
}

void	Network::setSocket(SOCKET socket)
{
	this->sock = socket;
}

void	Network::acceptClient()
{

}
