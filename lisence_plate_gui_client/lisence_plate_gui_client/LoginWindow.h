#pragma once

namespace lisence_plate_gui_client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginWindow
	/// </summary>
	public ref class LoginWindow : public System::Windows::Forms::Form
	{
	public:
		LoginWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->_serverPort = 4242;
			this->_serverIP = "127.0.0.1";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_connect;
	protected: 
	private: System::Windows::Forms::Label^  label_login;
	private: System::Windows::Forms::Label^  label_password;
	private: System::Windows::Forms::TextBox^  textBox_login;
	private: System::Windows::Forms::TextBox^  textBox_password;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem_options;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolStripMenuItem_servInfos;


	private: System::Windows::Forms::Label^  label_mainMsg;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginWindow::typeid));
			this->button_connect = (gcnew System::Windows::Forms::Button());
			this->label_login = (gcnew System::Windows::Forms::Label());
			this->label_password = (gcnew System::Windows::Forms::Label());
			this->textBox_login = (gcnew System::Windows::Forms::TextBox());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem_options = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolStripMenuItem_servInfos = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label_mainMsg = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_connect
			// 
			this->button_connect->Location = System::Drawing::Point(96, 137);
			this->button_connect->Name = L"button_connect";
			this->button_connect->Size = System::Drawing::Size(75, 21);
			this->button_connect->TabIndex = 0;
			this->button_connect->Text = L"Connection";
			this->button_connect->UseVisualStyleBackColor = true;
			this->button_connect->Click += gcnew System::EventHandler(this, &LoginWindow::button_connect_Click);
			// 
			// label_login
			// 
			this->label_login->AutoSize = true;
			this->label_login->Location = System::Drawing::Point(25, 61);
			this->label_login->Name = L"label_login";
			this->label_login->Size = System::Drawing::Size(32, 13);
			this->label_login->TabIndex = 1;
			this->label_login->Text = L"login:";
			// 
			// label_password
			// 
			this->label_password->AutoSize = true;
			this->label_password->Location = System::Drawing::Point(25, 97);
			this->label_password->Name = L"label_password";
			this->label_password->Size = System::Drawing::Size(55, 13);
			this->label_password->TabIndex = 2;
			this->label_password->Text = L"password:";
			// 
			// textBox_login
			// 
			this->textBox_login->Location = System::Drawing::Point(96, 58);
			this->textBox_login->Name = L"textBox_login";
			this->textBox_login->Size = System::Drawing::Size(100, 20);
			this->textBox_login->TabIndex = 3;
			// 
			// textBox_password
			// 
			this->textBox_password->Location = System::Drawing::Point(96, 94);
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(100, 20);
			this->textBox_password->TabIndex = 4;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripMenuItem_options});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(262, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem_options
			// 
			this->toolStripMenuItem_options->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ToolStripMenuItem_servInfos});
			this->toolStripMenuItem_options->Name = L"toolStripMenuItem_options";
			this->toolStripMenuItem_options->Size = System::Drawing::Size(61, 20);
			this->toolStripMenuItem_options->Text = L"Options";
			// 
			// ToolStripMenuItem_servInfos
			// 
			this->ToolStripMenuItem_servInfos->Name = L"ToolStripMenuItem_servInfos";
			this->ToolStripMenuItem_servInfos->Size = System::Drawing::Size(135, 22);
			this->ToolStripMenuItem_servInfos->Text = L"Server Infos";
			this->ToolStripMenuItem_servInfos->Click += gcnew System::EventHandler(this, &LoginWindow::ToolStripMenuItem_servInfos_Click);
			// 
			// label_mainMsg
			// 
			this->label_mainMsg->AutoSize = true;
			this->label_mainMsg->Location = System::Drawing::Point(51, 33);
			this->label_mainMsg->Name = L"label_mainMsg";
			this->label_mainMsg->Size = System::Drawing::Size(163, 13);
			this->label_mainMsg->TabIndex = 6;
			this->label_mainMsg->Text = L"Please login to use Lisence Plate";
			// 
			// LoginWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(262, 182);
			this->Controls->Add(this->label_mainMsg);
			this->Controls->Add(this->textBox_password);
			this->Controls->Add(this->textBox_login);
			this->Controls->Add(this->label_password);
			this->Controls->Add(this->label_login);
			this->Controls->Add(this->button_connect);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"LoginWindow";
			this->Text = L"Lisence Plate Client";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
private:
	System::String^	_serverIP;
	System::Int32	_serverPort;
	System::Void ToolStripMenuItem_servInfos_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void button_connect_Click(System::Object^  sender, System::EventArgs^  e);
};
}

