#pragma once
#include"Header.h"
#include <msclr/marshal_cppstd.h> 
//#include"MyForm.h"
using namespace msclr::interop;
namespace ProGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for fileListViewer
	/// </summary>
	public ref class fileListViewer : public System::Windows::Forms::Form
	{
	public:
		
		fileListViewer(FileSystemManager* manager) {  
			InitializeComponent();
			this->fsManager = manager;  // Store the native pointer
			UpdateStatus("Ready - displaying existing files list");
			LoadFileList();

			//Initializing the timer
			System::Windows::Forms::Timer^ timer = gcnew System::Windows::Forms::Timer();
			timer->Interval = 1000; // Update every second
			timer->Tick += gcnew System::EventHandler(this, &fileListViewer::OnTimerTick);
			timer->Start();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~fileListViewer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBoxFiles;
	private: System::Windows::Forms::TextBox^ textBoxContent;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelStatus;
		FileSystemManager* fsManager;
	private: System::Windows::Forms::Button^ buttonRefresh;


	private: System::Windows::Forms::Button^ buttonClose;
	private: System::Windows::Forms::TextBox^ textBoxSearch;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ time;

	private: System::Void OnTimerTick(System::Object^ sender, System::EventArgs^ e) {
		UpdateClock(); //Update the clock display
	}

	protected:

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
			this->listBoxFiles = (gcnew System::Windows::Forms::ListBox());
			this->textBoxContent = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->time = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listBoxFiles
			// 
			this->listBoxFiles->FormattingEnabled = true;
			this->listBoxFiles->ItemHeight = 20;
			this->listBoxFiles->Location = System::Drawing::Point(12, 105);
			this->listBoxFiles->Name = L"listBoxFiles";
			this->listBoxFiles->Size = System::Drawing::Size(281, 364);
			this->listBoxFiles->TabIndex = 0;
			this->listBoxFiles->SelectedIndexChanged += gcnew System::EventHandler(this, &fileListViewer::listBoxFiles_SelectedIndexChanged);
			// 
			// textBoxContent
			// 
			this->textBoxContent->BackColor = System::Drawing::Color::Beige;
			this->textBoxContent->Location = System::Drawing::Point(341, 105);
			this->textBoxContent->Multiline = true;
			this->textBoxContent->Name = L"textBoxContent";
			this->textBoxContent->ReadOnly = true;
			this->textBoxContent->Size = System::Drawing::Size(295, 364);
			this->textBoxContent->TabIndex = 1;
			this->textBoxContent->TextChanged += gcnew System::EventHandler(this, &fileListViewer::textBoxContent_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(343, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(171, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Choosen File Contents";
			this->label1->Click += gcnew System::EventHandler(this, &fileListViewer::label1_Click);
			// 
			// labelStatus
			// 
			this->labelStatus->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->labelStatus->Location = System::Drawing::Point(110, 568);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(526, 39);
			this->labelStatus->TabIndex = 3;
			this->labelStatus->Text = L"Displaying Existing Files List....";
			this->labelStatus->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->labelStatus->Click += gcnew System::EventHandler(this, &fileListViewer::labelStatus_Click);
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->BackColor = System::Drawing::Color::Khaki;
			this->buttonRefresh->Location = System::Drawing::Point(464, 484);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(82, 35);
			this->buttonRefresh->TabIndex = 4;
			this->buttonRefresh->Text = L"Refresh";
			this->buttonRefresh->UseVisualStyleBackColor = false;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &fileListViewer::buttonRefresh_Click_1);
			// 
			// buttonClose
			// 
			this->buttonClose->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonClose->Location = System::Drawing::Point(561, 484);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(75, 35);
			this->buttonClose->TabIndex = 6;
			this->buttonClose->Text = L"Close";
			this->buttonClose->UseVisualStyleBackColor = false;
			this->buttonClose->Click += gcnew System::EventHandler(this, &fileListViewer::buttonClose_Click);
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Location = System::Drawing::Point(12, 488);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(100, 26);
			this->textBoxSearch->TabIndex = 7;
			this->textBoxSearch->Text = L"Search files...";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(183, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Files on Virtual HardDisk";
			this->label2->Click += gcnew System::EventHandler(this, &fileListViewer::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 577);
			this->label3->Margin = System::Windows::Forms::Padding(0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Status Box";
			this->label3->Click += gcnew System::EventHandler(this, &fileListViewer::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(141, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(338, 29);
			this->label4->TabIndex = 10;
			this->label4->Text = L"List and View Existing Files";
			// 
			// time
			// 
			this->time->AutoSize = true;
			this->time->BackColor = System::Drawing::Color::NavajoWhite;
			this->time->Location = System::Drawing::Point(18, 15);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(39, 20);
			this->time->TabIndex = 11;
			this->time->Text = L"time";
			// 
			// fileListViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(648, 625);
			this->Controls->Add(this->time);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxSearch);
			this->Controls->Add(this->buttonClose);
			this->Controls->Add(this->buttonRefresh);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxContent);
			this->Controls->Add(this->listBoxFiles);
			this->Name = L"fileListViewer";
			this->Text = L"fileListViewer";
			this->Load += gcnew System::EventHandler(this, &fileListViewer::fileListViewer_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void fileListViewer_Load(System::Object^ sender, System::EventArgs^ e) {
		UpdateStatus("Initializing file viewer...");
		LoadFileList();
	}
	public:
    void ForceRefresh() {
        buttonRefresh_Click_1(nullptr, nullptr); // Call the refresh handler
    }
	private: System::Void listBoxFiles_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (listBoxFiles->SelectedIndex == -1) {
			textBoxContent->Clear();
			UpdateStatus("No file selected");
			return;
		}

		try {
			String^ selectedItem = safe_cast<String^>(listBoxFiles->SelectedItem);
			int parenIndex = selectedItem->IndexOf('(');
			String^ filename = selectedItem->Substring(0, parenIndex)->Trim();

			std::string nativeFilename = marshal_as<std::string>(filename);
			std::string content = fsManager->viewFile(nativeFilename);

			textBoxContent->Text = gcnew String(content.c_str());
			UpdateStatus("Displaying content of '" + filename + "' (" + content.length() + " characters)");
		}
		catch (Exception^ e) {
			textBoxContent->Text = "Error loading file content";
			UpdateStatus("Error: " + e->Message);
		}
	}

		 private: System::Void textBoxSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			 // 1. Get search text (make sure control name matches your designer)
			 String^ searchText = textBoxSearch->Text->ToLower();

			 // 2. Check if we have items to search
			 if (listBoxFiles->Items->Count == 0) return;

			 // 3. Search through items using proper collection access
			 bool found = false;
			 System::Collections::IEnumerator^ enumerator = listBoxFiles->Items->GetEnumerator();
			 int index = 0;

			 while (enumerator->MoveNext()) {
				 Object^ itemObj = enumerator->Current;
				 String^ item = itemObj->ToString()->ToLower();

				 if (item->Contains(searchText)) {
					 listBoxFiles->SetSelected(index, true);
					 found = true;
					 break;
				 }
				 index++;
			 }

			 // 4. Feedback if not found
			 if (!found) {
				 labelStatus->Text = "No matching files found";
			 }
		 }

	private:
		void LoadFileList() {
			try {
				listBoxFiles->Items->Clear();
				map<string, int> files = fsManager->listFiles();

				if (files.empty()) {
					UpdateStatus("No files found in virtual hard disk");
					return;
				}

				for (const auto& file : files) {
					String^ entry = gcnew String(file.first.c_str());
					entry += "   (" + file.second.ToString() + " bytes)";
					listBoxFiles->Items->Add(entry);
				}
				UpdateStatus("Loaded " + files.size() + " files from virtual hard disk");
			}
			catch (Exception^ e) {
				UpdateStatus("Error loading files: " + e->Message);
			}
		}

		// Status update helper method
		void UpdateStatus(String^ message) {
			/*labelStatus->Text = DateTime::Now.ToString("HH:mm:ss") + " - " + message;*/
			labelStatus->Text = message;
		}

		void UpdateClock() {
			time->Text = DateTime::Now.ToString("HH:mm:ss"); //clock label
		}
	private:
		System::Void textBoxContent_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void labelStatus_Click(System::Object^ sender, System::EventArgs^ e) { //this is status label
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonRefresh_Click_1(System::Object^ sender, System::EventArgs^ e) {
	try {
		UpdateStatus("Refreshing file list...");
		// Clear the current list
		listBoxFiles->Items->Clear();
		map<string, int> files = fsManager->listFiles();
		if (files.empty()) {
			labelStatus->Text = "No files found in the system";
			return;
		}
		for (const auto& file : files) {
			String^ entry = gcnew String(file.first.c_str());
			entry += " (" + file.second.ToString() + " bytes)";
			listBoxFiles->Items->Add(entry);
		}
		labelStatus->Text = "File list refreshed successfully!";

		// Clear the content viewer if nothing is selected
		if (listBoxFiles->SelectedIndex == -1) {
			textBoxContent->Clear();
		}
	}
	catch (Exception^ ex) {
		labelStatus->Text = "Error refreshing files: " + ex->Message;
	}
}
private: System::Void buttonClose_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		UpdateStatus("Closing file viewer...");
		// Close the form
		this->Close();
	}
	catch (Exception^ ex) {
		labelStatus->Text = "Error closing window: " + ex->Message;
	}
}
};
}
