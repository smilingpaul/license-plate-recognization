#include "StdAfx.h"
#include "ServerInfos.h"

using namespace lisence_plate_gui_client;

System::String^	ServerInfos::getIp()
{
	return (this->textBox_ip->Text);
}

System::Int32	ServerInfos::getPort()
{
	return (int::Parse(this->textBox_port->Text));
}