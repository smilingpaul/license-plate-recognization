// lisence_plate_gui_client.cpp : main project file.

#include "stdafx.h"
#include "LoginWindow.h"

using namespace lisence_plate_gui_client;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew LoginWindow());
	return 0;
}
