#ifndef __server_h__ 
#define __server_h__ 

#include <map>
#include <string>

#include <mswmdm.h>

class Server;
class clientInfos;

struct thread_param
{
       Server*	ser;
       SOCKET	soc;
	   int		id;
};

class	Server
{
private:
	DWORD							ClientThread(SOCKET, int);
public:
	Server();
	~Server();
	void							start();
	std::string						receiveLine(SOCKET);
	bool							checkAuth(std::string);
	bool							checkInXml(std::string, std::string);
	std::map<int, clientInfos*>		clientsMap;
	CRITICAL_SECTION				cs; 
	static DWORD WINAPI				ThreadLauncher(void *p)
	{
		struct thread_param *Obj = reinterpret_cast<struct thread_param*>(p);               
		Server *s = Obj->ser;
		return s->ClientThread(Obj->soc, Obj->id);
	}
};

#endif