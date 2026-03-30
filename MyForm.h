#pragma once
#include"MyForm1.h"
#include"MyForm2.h"
#include"MyForm3.h"
#include"MyForm4.h"
#include"MyForm5.h"
#include"MyForm7.h"
#include"MyForm6.h"
#include"Overall_Visualize.h"
#include"Defragmentation_Visualize.h"
#include"fileListViewer.h"
#include"Files.h"
#include"MemoryAllocator.h"
namespace ProGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			fsManager = new FileSystemManager();
			fileManager = new Files();
			memoryManager = new MemoryAllocator();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (fsManager) {
				delete fsManager;
				fsManager = nullptr; 
			}
			if (fileManager) {
				delete fileManager;
				fileManager = nullptr;
			}
			if (memoryManager) {
				delete memoryManager;
				memoryManager = nullptr;
			}

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ label1;
	private:
		FileSystemManager* fsManager;
		Files* fileManager;
		MemoryAllocator* memoryManager;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonClose;
	private: System::Windows::Forms::Button^ button8;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(57, 231);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(207, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Create new Files";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(57, 314);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(207, 35);
			this->button2->TabIndex = 1;
			this->button2->Text = L"List + View Existing Files";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(57, 398);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(207, 35);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Copy Files From Windows";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(412, 231);
			this->button4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(196, 35);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Copy Files To Windows";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(412, 314);
			this->button5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(196, 35);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Modify Files";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(412, 398);
			this->button6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(196, 35);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Delete Files";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(239, 472);
			this->button7->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(196, 35);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Apply Defregmentation";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Font = (gcnew System::Drawing::Font(L"High Tower Text", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(156, 145);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(349, 36);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Select the desired Option";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(244, 89);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(150, 29);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Main Menu";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(182, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(295, 39);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Virtual Hard-Disk";
			// 
			// buttonClose
			// 
			this->buttonClose->BackColor = System::Drawing::Color::Salmon;
			this->buttonClose->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonClose->Location = System::Drawing::Point(530, 34);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(120, 69);
			this->buttonClose->TabIndex = 12;
			this->buttonClose->Text = L"End Simulation";
			this->buttonClose->UseVisualStyleBackColor = false;
			this->buttonClose->Click += gcnew System::EventHandler(this, &MyForm::buttonClose_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Plum;
			this->button8->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(12, 34);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(142, 69);
			this->button8->TabIndex = 13;
			this->button8->Text = L"Visualize File Storage System";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(662, 542);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->buttonClose);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm1^ form1 = gcnew MyForm1(fsManager);  // Create a new instance
		this->Hide();                  // Optional: hide current form
		form1->ShowDialog();           // Show the new form modally
		this->Show();                  // Re-show original form when the new one is closed
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	fileListViewer^ viewer = gcnew fileListViewer(fsManager);
	//this->Hide();
	viewer->Show();
	//this->Show();
	// Open viewer as independent form

}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm2^ form2 = gcnew MyForm2(fsManager);  // Create a new instance
	this->Hide();                  // Optional: hide current form
	form2->ShowDialog();           // Show the new form modally
	this->Show();                  // Re-show original form when the new one is closed
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm5^ form5 = gcnew MyForm5(fsManager);  // Create a new instance
	this->Hide();                  // Optional: hide current form
	form5->ShowDialog();           // Show the new form modally
	this->Show();                  // Re-show original form when the new one is closed
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm3^ form3 = gcnew MyForm3(fsManager);  // Create a new instance
	this->Hide();                  // Optional: hide current form
	form3->ShowDialog();           // Show the new form modally
	this->Show();                  // Re-show original form when the new one is closed
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm4^ form4 = gcnew MyForm4(fsManager);  // Create a new instance
	this->Hide();                  // Optional: hide current form
	form4->ShowDialog();           // Show the new form modally
	this->Show();                  // Re-show original form when the new one is closed
}

private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	//Apply defragmentation and show visualization
	try {

		//Show the defragmented visualization
		Defragmentation_Visualize^ defragVisualizer = gcnew Defragmentation_Visualize(fsManager);
		defragVisualizer->Show();

	}
	catch (Exception^ ex) {
		MessageBox::Show("Error during defragmentation: " + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}
}

private: System::Void buttonClose_Click(System::Object^ sender, System::EventArgs^ e) {
	try {

		// Close the form
		this->Close();
	}
	catch (Exception^ ex) {}
}

private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	Overall_Visualize^ visualizer = gcnew Overall_Visualize(fsManager);
	visualizer->Show();              // Re-show original form when the new one is closed
	try {
		Overall_Visualize^ visualizer = gcnew Overall_Visualize(fsManager);
		visualizer->Show();            
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error opening overall visualization form: " + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}
}
};
}
