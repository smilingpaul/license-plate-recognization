#include "StdAfx.h"
#include "Interface.h"

using namespace lisence_plate_gui_client;

System::Void	Interface::my_init()
{
	this->label_logname->Text = "";
}

System::Void Interface::exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
}

System::Void Interface::disconnectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::Abort;
}

System::Void Interface::button_open_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->openFileDialog->ShowDialog();
	this->pictureBox->BackgroundImage = System::Drawing::Image::FromFile(this->openFileDialog->FileName);
	this->pictureBox->BackgroundImageLayout = ImageLayout::Stretch;
}

System::Void Interface::button_traitment_Click(System::Object^  sender, System::EventArgs^  e)
{
	/* Image traitment here. */
}
