#pragma once
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"
#include "MyForm5.h"
#include "Internet.h"

//#include <thread>


namespace CppWinForm4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Byte count;
		BufferedGraphicsContext^ context;
		BufferedGraphics^ grafx;
		Byte bufferingMode;
		array<String^>^bufferingModeStrings;
	public:
	int xx, yy;

	Bitmap ^ myBitmap1 = gcnew Bitmap("reiner_gamma.bmp");
	Bitmap ^ myBitmapOK = gcnew Bitmap("conectedOK.bmp");
	Bitmap ^ myBitmapNEOK = gcnew Bitmap("conectedNEOK.bmp");
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	public:

		// The ThreadProc method is called when the thread starts.
		// It loops ten times, writing to the console and yielding 
		// the rest of its time slice each time, and then ends.
		Thread^ thread;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		thread = gcnew Thread(gcnew ThreadStart(&MyForm::ThreadProcSafe));
			// If MyThreadFunc is an instance method, use "gcnew ThreadStart(this, &ClassName::MyThreadFunc)" to get the delegate.
		thread->Start();
			array<String^>^tempStrings = { "Draw to Form without OptimizedDoubleBufferring control style","Draw to Form using OptimizedDoubleBuffering control style","Draw to HDC for form" };
			bufferingModeStrings = tempStrings;

			bufferingMode = 2;
			count = 0;
			context = BufferedGraphicsManager::Current;
			context->MaximumBuffer = System::Drawing::Size(this->Width + 1, this->Height + 1);
			grafx = context->Allocate(this->pictureBox9->CreateGraphics(), Rectangle(0, 0, this->Width, this->Height));
			DrawToBuffer(grafx->Graphics);

			
		}
	

		static void ThreadProcSafe()
		{
			threadFunction();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	
		virtual void OnPaint(PaintEventArgs^ e) override
		{
			//grafx->Render(e->Graphics);
		}

	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox2;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox9;

	private: System::Windows::Forms::Timer^  timer1;

	private: System::Windows::Forms::TextBox^  textBox1;


	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->pictureBox4);
			this->groupBox1->Controls->Add(this->pictureBox3);
			this->groupBox1->Controls->Add(this->pictureBox2);
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(170, 726);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(6, 511);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(158, 158);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &MyForm::pictureBox4_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(6, 347);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(158, 158);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(6, 183);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(158, 158);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(6, 19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(158, 158);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->pictureBox5);
			this->groupBox2->Controls->Add(this->pictureBox6);
			this->groupBox2->Controls->Add(this->pictureBox7);
			this->groupBox2->Controls->Add(this->pictureBox8);
			this->groupBox2->Location = System::Drawing::Point(1082, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(170, 726);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(6, 511);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(158, 158);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 3;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(6, 347);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(158, 158);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 2;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &MyForm::pictureBox6_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(6, 183);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(158, 158);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 1;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Click += gcnew System::EventHandler(this, &MyForm::pictureBox7_Click);
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(6, 19);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(158, 158);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 0;
			this->pictureBox8->TabStop = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->pictureBox10);
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Controls->Add(this->pictureBox9);
			this->groupBox3->Location = System::Drawing::Point(188, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(888, 726);
			this->groupBox3->TabIndex = 5;
			this->groupBox3->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Location = System::Drawing::Point(844, 12);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(38, 37);
			this->pictureBox10->TabIndex = 6;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->Click += gcnew System::EventHandler(this, &MyForm::pictureBox10_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Visible = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// pictureBox9
			// 
			this->pictureBox9->Enabled = false;
			this->pictureBox9->Location = System::Drawing::Point(55, 40);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(788, 630);
			this->pictureBox9->TabIndex = 0;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox9_Paint);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 41;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1264, 750);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing_1);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			this->ResumeLayout(false);

		}
		
#pragma endregion
		void DrawToBuffer(Graphics^ g)
		{
			// Clear the graphics buffer every five updates.
			
			grafx->Graphics->DrawImage(myBitmap1, 0, 0);
			grafx->Graphics->DrawString(String::Format("Скор.:{0} м/с", Convert::ToInt32(dvs_stat_t1.rpm[0])), gcnew System::Drawing::Font("Arial", 20), gcnew SolidBrush(Color::Lime), 788 - 20 - 200 + 1, 50 + 7); // Координаты размещения текста
			Pen^ LimePen = gcnew Pen(Color::Lime, 3.0f);
			grafx->Graphics->DrawRectangle(LimePen, 788 - 20 - 200, 50, 200, 50);
			grafx->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Lime), Rectangle(394 - 18 + acs_stat_t1.angl[0] * 4.3, 0, 36, 15));
			grafx->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Lime), Rectangle(0, 314 - 18 + acs_stat_t1.angl[1] * 3.5, 15, 36));
			grafx->Graphics->FillEllipse(gcnew SolidBrush(Color::Red), 394, 315, 10, 10);


			// Draw randomly positioned and colored ellipses.

		}

		void threadFunctionStart() {
			threadFunction();
		}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {

		MyForm1 ^Myform1 = gcnew MyForm1();
		//Myform1->ShowDialog();
	}
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm2 ^Myform2 = gcnew MyForm2();
	//Myform2->ShowDialog();
}
private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm3 ^Myform3 = gcnew MyForm3();
	Myform3->ShowDialog();
}
private: System::Void pictureBox7_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm4 ^Myform4 = gcnew MyForm4();
	//Myform4->ShowDialog();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	DrawToBuffer(grafx->Graphics);

	// If in bufferingMode 2, draw to the form's HDC.
	if (bufferingMode == 2)

		// Render the graphics buffer to the form's HDC.
		grafx->Render(this->pictureBox9->CreateGraphics());
	// If in bufferingMode 0 or 1, draw in the paint method.
	else

		// If in bufferingMode 0 or 1, draw in the paint method.
		this->Refresh();

	
		if (connceted == true) {
			pictureBox2->Image = myBitmapOK;
					}
		else {
			pictureBox2->Image = myBitmapNEOK;

					}
	
	
	
}

private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	
}
private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	
}
private: System::Void textBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void fontDialog1_Apply(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	
	
}
private: System::Void MyForm_FormClosing_1(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	
}
private: System::Void pictureBox9_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {





}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	xx = 50;
	yy = 50;
	dvs_stat_t1.rpm[1] = '12';
	
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox3_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm5 ^Myform5 = gcnew MyForm5();
	Myform5->ShowDialog();





}
private: System::Void pictureBox6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox10_Click(System::Object^  sender, System::EventArgs^  e) {
	closedform = true;
	MyForm::Close();
}
};
}
