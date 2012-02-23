#ifndef __clientInfos_h__ 
#define __clientInfos_h__ 

#include "server.h"

class	clientInfos
{
public:
	clientInfos(bool auth);
	~clientInfos();
	bool		isAuth;
	SOCKET		getSocket();
	void		setSocket(SOCKET);
	SOCKADDR_IN	getAddr();
	void		setAddr(SOCKADDR_IN);
	int			getAddrLen();
	void		setAddrLen(int);
private:
	SOCKET			soc;
	SOCKADDR_IN		addr;
	int             addrLen;
};

#endif