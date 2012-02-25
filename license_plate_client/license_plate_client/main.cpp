#include <iostream>
#include <fstream>
#include "network.h"



DWORD DGetFileSize(FILE* Fichier)
{
    // sauvegarder la position courante
    long pos = ftell(Fichier);
    // se placer en fin de fichier
    fseek(Fichier, 0 , SEEK_END);
    // récupérer la nouvelle position = la taille du fichier
    long size = ftell(Fichier) ;
    // restaurer la position initiale du fichier
    fseek(Fichier, pos, SEEK_SET) ;
    return size ;
}

int main()
{
	Network nt;
	HANDLE	picture;
	DWORD	header;
	//DWORD	filesize;
	std::string	data;
	//TRANSMIT_FILE_BUFFERS	h;

	std::string s = "max|pass";
	s += '\n';
	header = 3;
	send(nt.getSocket(), reinterpret_cast<const char*>(&header), sizeof(DWORD), 0);
	send(nt.getSocket(),s.c_str(),s.length(),0);
	
	header = 2;
	send(nt.getSocket(), reinterpret_cast<const char*>(&header), sizeof(DWORD), 0);
	
	FILE *fw = fopen("builder.jpg", "rb");
	long filesize = DGetFileSize(fw);
	int filesizes = filesize;
	send(nt.getSocket(), reinterpret_cast<const char*>(&filesizes), sizeof(int), 0);
	//filesize = GetFileSize(fw, NULL);
	while (filesize > 0)
	{
		char buffer[1030];

		if (filesize >= 1024)
		{
			fread(buffer, 1024, 1, fw);
			send(nt.getSocket(), buffer, 1024, 0);
		}
		else
		{
			fread(buffer, filesize, 1, fw);
			//recv(soc, buffer, filesize, 0 );
			buffer[filesize] = '\0';
			send(nt.getSocket(), buffer, filesize, 0);
			//fwrite(buffer, filesize, 1, fw);
		}
		filesize -= 1024;
	}
	fclose(fw);
	
	/*picture = CreateFile("builder.jpg",GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_FLAG_SEQUENTIAL_SCAN,NULL);
	filesize = GetFileSize(picture, NULL);
	*/
	/*h.Head = reinterpret_cast<PVOID>(filesize);
	DWORD size = reinterpret_cast<DWORD>(h.Head);
	h.HeadLength = sizeof(h.Head);
	h.TailLength = 0;*/
	/*header = 2;
	send(nt.getSocket(), reinterpret_cast<const char*>(&header), sizeof(DWORD), 0);
	send(nt.getSocket(), reinterpret_cast<const char*>(&filesize), sizeof(DWORD), 0);
	TransmitFile(nt.getSocket(), picture, 0, 0, NULL, NULL, NULL);*/
	while (1)
	{
		;
	}

}
