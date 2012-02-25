#include "stdafx.h"
#include "LoginWindow.h"
#include "ServerInfos.h"
#include "Interface.h"

//#include <iostream>
//#include <fstream>
//#include "network.h"


using namespace lisence_plate_gui_client;

System::Void LoginWindow::ToolStripMenuItem_servInfos_Click(System::Object^  sender, System::EventArgs^  e)
{
	ServerInfos	servInfos;
	if (servInfos.ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->_serverIP = servInfos.getIp();
		this->_serverPort = servInfos.getPort();
	}
}

//void MarshalString ( String ^ s, std::string& os ) {
//	using namespace Runtime::InteropServices;
//	const char* chars = 
//		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
//	os = chars;
//	Marshal::FreeHGlobal(IntPtr((void*)chars));
//}

System::Void LoginWindow::button_connect_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool	connect = true;

	/*Connect here*/
/*link*/
//	Network nt;
//	HANDLE	picture;
//	DWORD	header;
//	//DWORD	filesize;
//	std::string	data;
//	//TRANSMIT_FILE_BUFFERS	h;
//	std::string s;
//	MarshalString(this->textBox_login->Text + "|" + this->textBox_password->Text + "\n", s);
////	std::string s = this->textBox_login->Text + "|" + this->textBox_password->Text + "\n";
////	s += '\n';
//	header = 3;
//	send(nt.getSocket(), reinterpret_cast<const char*>(&header), sizeof(DWORD), 0);
//	send(nt.getSocket(),s.c_str(),s.length(),0);
/*!link*/
	if (connect)
	{
		System::Windows::Forms::DialogResult	res;
		Interface								mainwindow;

		this->Hide();
		res = mainwindow.ShowDialog();
		/*Disconnect here*/
		if (res == System::Windows::Forms::DialogResult::Cancel)
			Application::Exit();
		else
			this->Show();
	}
}