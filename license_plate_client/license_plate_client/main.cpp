#include "network.h"

int main()
{
	Network nt;
	HANDLE	picture;
	DWORD	filesize;
	std::string	data;
	//TRANSMIT_FILE_BUFFERS	h;

	std::string s = "max|pass";
	s += '\n';
	send(nt.getSocket(),s.c_str(),s.length(),0);
	
	picture = CreateFile("builder.jpg",GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_FLAG_SEQUENTIAL_SCAN,NULL);
	filesize = GetFileSize(picture, NULL);
	/*h.Head = reinterpret_cast<PVOID>(filesize);
	DWORD size = reinterpret_cast<DWORD>(h.Head);
	h.HeadLength = sizeof(h.Head);
	h.TailLength = 0;*/
	send(nt.getSocket(), reinterpret_cast<const char*>(&filesize), sizeof(DWORD), 0);
	TransmitFile(nt.getSocket(), picture, 0, 0, NULL, NULL, NULL);
	while (1)
	{
		;
	}

}