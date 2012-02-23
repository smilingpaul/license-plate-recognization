#include <iostream>
#include <mswmdm.h>

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

	void		acceptClient();
private:
	SOCKET		sock;
	SOCKADDR_IN sin;
	int			port;
};