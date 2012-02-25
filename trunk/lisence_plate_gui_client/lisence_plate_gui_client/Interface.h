#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace lisence_plate_gui_client {

	/// <summary>
	/// Summary for Interface
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Interface : public System::Windows::Forms::Form
	{
	public:
		Interface(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->my_init();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Interface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip;
	protected: 

	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  disconnectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: System::Windows::Forms::Button^  button_open;
	private: System::Windows::Forms::Button^  button_traitment;


	private: System::Windows::Forms::Label^  label_imgprev;
	private: System::Windows::Forms::Label^  label_imginfos;
	private: System::Windows::Forms::Label^  label_imgname;
	private: System::Windows::Forms::Label^  label_imgplate;
	private: System::Windows::Forms::Label^  label_connectas;

	private: System::Windows::Forms::Label^  label_state;






	private: System::Windows::Forms::TextBox^  textBox_imgname;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label_logname;
	private: System::Windows::Forms::Label^  label_state2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;




	private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Interface::typeid));
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->disconnectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->button_open = (gcnew System::Windows::Forms::Button());
			this->button_traitment = (gcnew System::Windows::Forms::Button());
			this->label_imgprev = (gcnew System::Windows::Forms::Label());
			this->label_imginfos = (gcnew System::Windows::Forms::Label());
			this->label_imgname = (gcnew System::Windows::Forms::Label());
			this->label_imgplate = (gcnew System::Windows::Forms::Label());
			this->label_connectas = (gcnew System::Windows::Forms::Label());
			this->label_state = (gcnew System::Windows::Forms::Label());
			this->textBox_imgname = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label_logname = (gcnew System::Windows::Forms::Label());
			this->label_state2 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->optionsToolStripMenuItem});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(558, 24);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->disconnectToolStripMenuItem, 
				this->exitToolStripMenuItem});
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// disconnectToolStripMenuItem
			// 
			this->disconnectToolStripMenuItem->Name = L"disconnectToolStripMenuItem";
			this->disconnectToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->disconnectToolStripMenuItem->Text = L"Disconnect";
			this->disconnectToolStripMenuItem->Click += gcnew System::EventHandler(this, &Interface::disconnectToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Interface::exitToolStripMenuItem_Click);
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(12, 63);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(169, 141);
			this->pictureBox->TabIndex = 1;
			this->pictureBox->TabStop = false;
			// 
			// button_open
			// 
			this->button_open->Location = System::Drawing::Point(12, 219);
			this->button_open->Name = L"button_open";
			this->button_open->Size = System::Drawing::Size(169, 23);
			this->button_open->TabIndex = 2;
			this->button_open->Text = L"Load image";
			this->button_open->UseVisualStyleBackColor = true;
			this->button_open->Click += gcnew System::EventHandler(this, &Interface::button_open_Click);
			// 
			// button_traitment
			// 
			this->button_traitment->Location = System::Drawing::Point(12, 248);
			this->button_traitment->Name = L"button_traitment";
			this->button_traitment->Size = System::Drawing::Size(169, 23);
			this->button_traitment->TabIndex = 3;
			this->button_traitment->Text = L"Traitment";
			this->button_traitment->UseVisualStyleBackColor = true;
			this->button_traitment->Click += gcnew System::EventHandler(this, &Interface::button_traitment_Click);
			// 
			// label_imgprev
			// 
			this->label_imgprev->AutoSize = true;
			this->label_imgprev->Location = System::Drawing::Point(13, 44);
			this->label_imgprev->Name = L"label_imgprev";
			this->label_imgprev->Size = System::Drawing::Size(76, 13);
			this->label_imgprev->TabIndex = 4;
			this->label_imgprev->Text = L"Image preview";
			// 
			// label_imginfos
			// 
			this->label_imginfos->AutoSize = true;
			this->label_imginfos->Location = System::Drawing::Point(323, 44);
			this->label_imginfos->Name = L"label_imginfos";
			this->label_imginfos->Size = System::Drawing::Size(96, 13);
			this->label_imginfos->TabIndex = 5;
			this->label_imginfos->Text = L"Image Informations";
			// 
			// label_imgname
			// 
			this->label_imgname->AutoSize = true;
			this->label_imgname->Location = System::Drawing::Point(238, 99);
			this->label_imgname->Name = L"label_imgname";
			this->label_imgname->Size = System::Drawing::Size(68, 13);
			this->label_imgname->TabIndex = 6;
			this->label_imgname->Text = L"Image name:";
			// 
			// label_imgplate
			// 
			this->label_imgplate->AutoSize = true;
			this->label_imgplate->Location = System::Drawing::Point(238, 156);
			this->label_imgplate->Name = L"label_imgplate";
			this->label_imgplate->Size = System::Drawing::Size(74, 13);
			this->label_imgplate->TabIndex = 7;
			this->label_imgplate->Text = L"Plate Number:";
			// 
			// label_connectas
			// 
			this->label_connectas->AutoSize = true;
			this->label_connectas->Location = System::Drawing::Point(238, 273);
			this->label_connectas->Name = L"label_connectas";
			this->label_connectas->Size = System::Drawing::Size(76, 13);
			this->label_connectas->TabIndex = 8;
			this->label_connectas->Text = L"Connected as:";
			// 
			// label_state
			// 
			this->label_state->AutoSize = true;
			this->label_state->Location = System::Drawing::Point(407, 273);
			this->label_state->Name = L"label_state";
			this->label_state->Size = System::Drawing::Size(35, 13);
			this->label_state->TabIndex = 9;
			this->label_state->Text = L"State:";
			// 
			// textBox_imgname
			// 
			this->textBox_imgname->Location = System::Drawing::Point(326, 96);
			this->textBox_imgname->Name = L"textBox_imgname";
			this->textBox_imgname->ReadOnly = true;
			this->textBox_imgname->Size = System::Drawing::Size(186, 20);
			this->textBox_imgname->TabIndex = 10;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(326, 149);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(186, 20);
			this->textBox1->TabIndex = 11;
			// 
			// label_logname
			// 
			this->label_logname->AutoSize = true;
			this->label_logname->Location = System::Drawing::Point(321, 273);
			this->label_logname->Name = L"label_logname";
			this->label_logname->Size = System::Drawing::Size(0, 13);
			this->label_logname->TabIndex = 12;
			// 
			// label_state2
			// 
			this->label_state2->AutoSize = true;
			this->label_state2->Location = System::Drawing::Point(448, 273);
			this->label_state2->Name = L"label_state2";
			this->label_state2->Size = System::Drawing::Size(0, 13);
			this->label_state2->TabIndex = 13;
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"car_image";
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 295);
			this->Controls->Add(this->label_state2);
			this->Controls->Add(this->label_logname);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox_imgname);
			this->Controls->Add(this->label_state);
			this->Controls->Add(this->label_connectas);
			this->Controls->Add(this->label_imgplate);
			this->Controls->Add(this->label_imgname);
			this->Controls->Add(this->label_imginfos);
			this->Controls->Add(this->label_imgprev);
			this->Controls->Add(this->button_traitment);
			this->Controls->Add(this->button_open);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->menuStrip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"Interface";
			this->Text = L"Lisence Plate Client";
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void disconnectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_open_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_traitment_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void my_init();
};
}
