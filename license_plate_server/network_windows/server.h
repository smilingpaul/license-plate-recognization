#ifndef __server_h__ 
#define __server_h__ 

#include <map>
#include <string>

#include <mswmdm.h>

class Server;
class clientInfos;

#define QUIT_SERVER 1
#define SEND_PICTURE 2
#define CHECK_AUTH 3

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
	void							receivePicture(SOCKET);
	void							checkAuth(SOCKET, clientInfos*);
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