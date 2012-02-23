#ifndef __network_h__ 
#define __network_h__ 


#include <iostream>
#include <mswmdm.h>
#include "clientInfos.h"

class	Network
{
public:
	Network();
	~Network();
	SOCKET		getSocket();
	void		setSocket(SOCKET);
	SOCKADDR_IN	getSockAddr();
	void		setSockAddr(SOCKADDR_IN);
	void		fillSockAddr();

	SOCKET		acceptClient(clientInfos *p);
private:
	SOCKET		sock;
	SOCKADDR_IN sin;
	int			port;
};

#endif