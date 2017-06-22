#pragma once
#include "Internet.h"
namespace CppWinForm4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm5
	/// </summary>
	public ref class MyForm5 : public System::Windows::Forms::Form
	{
		unsigned short speed = 100;
		int ii = 0;

	public:
		Bitmap ^ myBitmapSlover = gcnew Bitmap("Slover.bmp");
		Bitmap ^ myBitmapFaste = gcnew Bitmap("Faste.bmp");

		Bitmap ^ myBitmapSloverRed = gcnew Bitmap("SloverRed.bmp");
	private: System::Windows::Forms::Label^  label6;
	public:
		Bitmap ^ myBitmapFasteRed = gcnew Bitmap("FasteRed.bmp");

		MyForm5(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			dvs_com_t1.index = 'C';
			dvs_com_t1.seq = '0';
			//dvs_com_t1.r = 0;
			label6->Text = String::Format("Ускорение: {0}", speed);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm5()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm5::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1132, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(104, 103);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm5::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(370, 188);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(158, 158);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm5::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(370, 352);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(158, 158);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm5::pictureBox3_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(715, 352);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(158, 158);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 5;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &MyForm5::pictureBox5_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(715, 188);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(158, 158);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 4;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &MyForm5::pictureBox4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 40));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(12, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 61);
			this->label1->TabIndex = 6;
			this->label1->Text = L"1";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm5::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 40));
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(12, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 61);
			this->label2->TabIndex = 7;
			this->label2->Text = L"2";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm5::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Black;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 40));
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(12, 152);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 61);
			this->label3->TabIndex = 8;
			this->label3->Text = L"3";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm5::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Black;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 40));
			this->label4->ForeColor = System::Drawing::Color::Lime;
			this->label4->Location = System::Drawing::Point(12, 158);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 61);
			this->label4->TabIndex = 9;
			this->label4->Text = L"4";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm5::label4_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 24));
			this->groupBox1->ForeColor = System::Drawing::Color::Lime;
			this->groupBox1->Location = System::Drawing::Point(935, 200);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(250, 292);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Режим";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Location = System::Drawing::Point(31, 43);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(75, 222);
			this->groupBox3->TabIndex = 11;
			this->groupBox3->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Location = System::Drawing::Point(149, 43);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(75, 222);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Black;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 40));
			this->label6->ForeColor = System::Drawing::Color::Lime;
			this->label6->Location = System::Drawing::Point(816, 124);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(57, 61);
			this->label6->TabIndex = 9;
			this->label6->Text = L"1";
			// 
			// MyForm5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1248, 712);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm5";
			this->Text = L"MyForm5";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		MyForm5::Close();
	}
private: System::Void pictureBox2_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//Начинаем ход вперед
	    //dvs_com_t1.r = 2;
		dvs_com_t1.com[0] = speed;
		dvs_com_t1.com[1] = speed;
		dvs_com_t1.com[2] = speed;
		dvs_com_t1.com[3] = speed;
		sended = false;
		
}
private: System::Void pictureBox3_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//Начинаем ход назад
	//dvs_com_t1.r = 3;
	dvs_com_t1.com[0] = speed;
	dvs_com_t1.com[1] = speed;
	dvs_com_t1.com[2] = speed;
	dvs_com_t1.com[3] = speed;
	
	sended = false;

}
private: System::Void pictureBox2_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//Прекращаем ход вперед
	dvs_com_t1.com[0] = 0;
	dvs_com_t1.com[1] = 0;
	dvs_com_t1.com[2] = 0;
	dvs_com_t1.com[3] = 0;
	sended = false;
}
private: System::Void pictureBox3_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//Прекращаем ход Назад
	dvs_com_t1.com[0] = 0;
	dvs_com_t1.com[1] = 0;
	dvs_com_t1.com[2] = 0;
	dvs_com_t1.com[3] = 0;
	sended = false;



}



private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	dvs_com_t1.r = 0;
	sended = false;
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	dvs_com_t1.r = 2;
	sended = false;
	pictureBox2->Enabled = true;
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	dvs_com_t1.r = 1;
	sended = false;
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
	dvs_com_t1.r = 3;
	sended = false;
}
private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) {
	
		speed = speed + 100;
		label6->Text = String::Format("Ускорение: {0}", speed);
	
	/*
	if (ii <= 3) {
		speed = speed + 100;
		ii++;
		label6->Text = String::Format("Ускорение: {0}", speed);

		pictureBox4->Image = myBitmapFaste;
		if (ii != 0) {
			pictureBox5->Image = myBitmapSlover;
			pictureBox5->Enabled = true;
		}
		if (ii == 3) {
			pictureBox4->Image = myBitmapFasteRed;
			pictureBox4->Enabled = false;
		}
	}*/
}
private: System::Void pictureBox5_Click(System::Object^  sender, System::EventArgs^  e) {
	if (speed != 0) {
		speed = speed - 100;;
		label6->Text = String::Format("Ускорение: {0}", speed);
	}
	/*if (ii > -1) {
		speed = speed - 100;
		ii--;
		label6->Text = String::Format("Ускорение: {0}", speed);
		pictureBox5->Image = myBitmapSlover;
		if (ii != 3) {
			pictureBox4->Image = myBitmapFaste;
			pictureBox4->Enabled = true;
		}
		if (ii == 0) {
			pictureBox5->Image = myBitmapSloverRed;
			pictureBox5->Enabled = false;
		}
	}*/
}


private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	dvs_com_t1.com[0] = speed;
	dvs_com_t1.com[1] = speed;
	dvs_com_t1.com[2] = speed;
	dvs_com_t1.com[3] = speed;
	sended = false;
	label6->Text = String::Format("Ускорение: {0}", speed);

}
private: System::Void pictureBox3_Click(System::Object^  sender, System::EventArgs^  e) {
	
	speed = 0;
	dvs_com_t1.com[0] = speed;
	dvs_com_t1.com[1] = speed;
	dvs_com_t1.com[2] = speed;
	dvs_com_t1.com[3] = speed;
	label6->Text = String::Format("Ускорение: {0}", speed);

	sended = false;
}
};
}
