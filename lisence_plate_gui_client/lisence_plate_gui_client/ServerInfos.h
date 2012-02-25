#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lisence_plate_gui_client {

	/// <summary>
	/// Summary for ServerInfos
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ServerInfos : public System::Windows::Forms::Form
	{
	public:
		ServerInfos(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ServerInfos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_ok;
	protected: 
	private: System::Windows::Forms::Button^  button_cancel;
	private: System::Windows::Forms::TextBox^  textBox_ip;
	private: System::Windows::Forms::TextBox^  textBox_port;
	private: System::Windows::Forms::Label^  label_servinfos;



	private: System::Windows::Forms::Label^  label_ip;
	private: System::Windows::Forms::Label^  label_port;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ServerInfos::typeid));
			this->button_ok = (gcnew System::Windows::Forms::Button());
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->textBox_ip = (gcnew System::Windows::Forms::TextBox());
			this->textBox_port = (gcnew System::Windows::Forms::TextBox());
			this->label_servinfos = (gcnew System::Windows::Forms::Label());
			this->label_ip = (gcnew System::Windows::Forms::Label());
			this->label_port = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_ok
			// 
			this->button_ok->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_ok->Location = System::Drawing::Point(16, 114);
			this->button_ok->Name = L"button_ok";
			this->button_ok->Size = System::Drawing::Size(75, 23);
			this->button_ok->TabIndex = 0;
			this->button_ok->Text = L"OK";
			this->button_ok->UseVisualStyleBackColor = true;
			// 
			// button_cancel
			// 
			this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_cancel->Location = System::Drawing::Point(104, 114);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(75, 23);
			this->button_cancel->TabIndex = 1;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			// 
			// textBox_ip
			// 
			this->textBox_ip->Location = System::Drawing::Point(51, 34);
			this->textBox_ip->MaxLength = 15;
			this->textBox_ip->Name = L"textBox_ip";
			this->textBox_ip->Size = System::Drawing::Size(128, 20);
			this->textBox_ip->TabIndex = 2;
			this->textBox_ip->Text = L"127.0.0.1";
			// 
			// textBox_port
			// 
			this->textBox_port->Location = System::Drawing::Point(51, 70);
			this->textBox_port->MaxLength = 5;
			this->textBox_port->Name = L"textBox_port";
			this->textBox_port->Size = System::Drawing::Size(128, 20);
			this->textBox_port->TabIndex = 3;
			this->textBox_port->Text = L"4242";
			// 
			// label_servinfos
			// 
			this->label_servinfos->AutoSize = true;
			this->label_servinfos->Location = System::Drawing::Point(45, 9);
			this->label_servinfos->Name = L"label_servinfos";
			this->label_servinfos->Size = System::Drawing::Size(101, 13);
			this->label_servinfos->TabIndex = 4;
			this->label_servinfos->Text = L"Server Informations:";
			// 
			// label_ip
			// 
			this->label_ip->AutoSize = true;
			this->label_ip->Location = System::Drawing::Point(13, 40);
			this->label_ip->Name = L"label_ip";
			this->label_ip->Size = System::Drawing::Size(20, 13);
			this->label_ip->TabIndex = 5;
			this->label_ip->Text = L"IP:";
			// 
			// label_port
			// 
			this->label_port->AutoSize = true;
			this->label_port->Location = System::Drawing::Point(9, 73);
			this->label_port->Name = L"label_port";
			this->label_port->Size = System::Drawing::Size(29, 13);
			this->label_port->TabIndex = 6;
			this->label_port->Text = L"Port:";
			// 
			// ServerInfos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(193, 154);
			this->Controls->Add(this->label_port);
			this->Controls->Add(this->label_ip);
			this->Controls->Add(this->label_servinfos);
			this->Controls->Add(this->textBox_port);
			this->Controls->Add(this->textBox_ip);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_ok);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"ServerInfos";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"ServerInfos";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	System::String^	getIp();
	System::Int32	getPort();
	};
}
