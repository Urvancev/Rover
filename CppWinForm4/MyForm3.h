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
	/// Сводка для MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{

	public:
		MyForm3(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;








	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;












	private: System::Windows::Forms::GroupBox^  groupBox3;





	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;


	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm3::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1148, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(104, 103);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm3::pictureBox1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::LimeGreen;
			this->label5->Location = System::Drawing::Point(10, 58);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 36);
			this->label5->TabIndex = 9;
			this->label5->Text = L"1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::LimeGreen;
			this->label6->Location = System::Drawing::Point(10, 124);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(33, 36);
			this->label6->TabIndex = 10;
			this->label6->Text = L"3";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::LimeGreen;
			this->label7->Location = System::Drawing::Point(174, 124);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(33, 36);
			this->label7->TabIndex = 11;
			this->label7->Text = L"4";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::LimeGreen;
			this->label8->Location = System::Drawing::Point(174, 58);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 36);
			this->label8->TabIndex = 12;
			this->label8->Text = L"2";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 24));
			this->groupBox1->ForeColor = System::Drawing::Color::Lime;
			this->groupBox1->Location = System::Drawing::Point(53, 255);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(319, 181);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Двигатели:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(213, 124);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(98, 36);
			this->label4->TabIndex = 16;
			this->label4->Text = L"label4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(49, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 36);
			this->label3->TabIndex = 15;
			this->label3->Text = L"label3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(213, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 36);
			this->label2->TabIndex = 14;
			this->label2->Text = L"label2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(49, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 36);
			this->label1->TabIndex = 13;
			this->label1->Text = L"label1";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 24));
			this->groupBox2->ForeColor = System::Drawing::Color::Lime;
			this->groupBox2->Location = System::Drawing::Point(393, 255);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(362, 181);
			this->groupBox2->TabIndex = 14;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"АКБ:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(145, 124);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(116, 36);
			this->label12->TabIndex = 20;
			this->label12->Text = L"label12";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(24, 124);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(114, 36);
			this->label11->TabIndex = 19;
			this->label11->Text = L"label11";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(145, 58);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(116, 36);
			this->label10->TabIndex = 18;
			this->label10->Text = L"label10";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(24, 58);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(98, 36);
			this->label9->TabIndex = 17;
			this->label9->Text = L"label9";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Arial", 24));
			this->groupBox3->ForeColor = System::Drawing::Color::Lime;
			this->groupBox3->Location = System::Drawing::Point(761, 255);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(363, 181);
			this->groupBox3->TabIndex = 15;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Процессор:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(195, 124);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(116, 36);
			this->label16->TabIndex = 24;
			this->label16->Text = L"label16";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(195, 58);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(116, 36);
			this->label15->TabIndex = 23;
			this->label15->Text = L"label15";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(20, 124);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(116, 36);
			this->label14->TabIndex = 22;
			this->label14->Text = L"label14";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(20, 58);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(116, 36);
			this->label13->TabIndex = 21;
			this->label13->Text = L"label13";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm3::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 500;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm3::timer2_Tick);
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1264, 750);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm3";
			this->Text = L"MyForm3";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm3::MyForm3_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm3_Load(System::Object^  sender, System::EventArgs^  e) {
		label1->Text = "";
		label2->Text = "";
		label3->Text = "";
		label4->Text = "";
		label9->Text = "";
		label10->Text = "";
		label11->Text = "";
		label12->Text = "";
		label13->Text = "";
		label14->Text = "";
		label15->Text = "";
		label16->Text = "";


	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		MyForm3::Close();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		switch (dvs_stat_t1.enable[0])//1 двигатель
		{
		case '1'://1 всё ок
			label1->Text = String::Format("{0}°C", dvs_stat_t1.temp[0]);
			label1->ForeColor = Color::Lime;
			break;
		case '0'://всё не ок
			label1->Text = String::Format("{0}°C", dvs_stat_t1.temp[0]);
			label1->ForeColor = Color::Red;
			break;
		}
		switch (dvs_stat_t1.enable[1])//2 двигатель
		{
		case '1'://1 всё ок
			label2->Text = String::Format("{0}°C", dvs_stat_t1.temp[1]);
			label2->ForeColor = Color::Lime;
			break;
		case '0'://всё не ок
			label2->Text = String::Format("{0}°C", dvs_stat_t1.temp[1]);
			label2->ForeColor = Color::Red;
			break;
		}
		switch (dvs_stat_t1.enable[2])//3 двигатель
		{
		case '1'://1 всё ок
			label3->Text = String::Format("{0}°C", dvs_stat_t1.temp[2]);
			label3->ForeColor = Color::Lime;
			break;
		case '0'://всё не ок
			label3->Text = String::Format("{0}°C", dvs_stat_t1.temp[2]);
			label3->ForeColor = Color::Red;
			break;
		}
		switch (dvs_stat_t1.enable[3])//4 двигатель
		{
		case '1'://1 всё ок
			label4->Text = String::Format("{0}°C", dvs_stat_t1.temp[3]);
			label4->ForeColor = Color::Lime;
			break;
		case '0'://всё не ок
			label4->Text = String::Format("{0}°C", dvs_stat_t1.temp[3]);
			label4->ForeColor = Color::Red;
			break;
		}


					
				






			}

		private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {

			switch (akb_stat_t1.enable)//1 двигатель
			{
			case '1'://1 всё ок
				label9->Text = String::Format("{0}°C", akb_stat_t1.temp);
				label9->ForeColor = Color::Lime;

				//G9->DrawString(String::Format("{0}°C", akb_stat_t1.temp), gcnew System::Drawing::Font("Arial", 20), gcnew SolidBrush(Color::Lime), 5, 5); // Координаты размещения текста
				break;
			case '0'://всё не ок
				label9->Text = String::Format("{0}°C", akb_stat_t1.temp);
				label9->ForeColor = Color::Red;

				//G9->DrawString(String::Format("{0}°C", akb_stat_t1.temp), gcnew System::Drawing::Font("Arial", 20), gcnew SolidBrush(Color::Red), 5, 5); // Координаты размещения текста
				break;
			}

		}
};
	}
	
