#pragma once
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "Files.h"
#include "MemoryAllocator.h"
#include"Header.h"

namespace ProGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;  // For marshaling

	public ref class MyForm6 : public System::Windows::Forms::Form
	{
	public:

		MyForm6(Files* fm, MemoryAllocator* mm, FileSystemManager* manager)
		{
			InitializeComponent();
			fileManager = fm;
			memoryManager = mm;
			fa = manager;
		}

	protected:
		~MyForm6()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ File_Names_Address;
	private: System::Windows::Forms::ListBox^ Available_Addresses;
	protected:

	protected:

	protected:

	protected:



	private: System::Windows::Forms::Button^ loadButton;
	private: System::Windows::Forms::Button^ defragButton;
	private: System::ComponentModel::Container^ components;
		   FileSystemManager* fa;
		   Files* fileManager;
		   MemoryAllocator* memoryManager;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->File_Names_Address = (gcnew System::Windows::Forms::ListBox());
			   this->Available_Addresses = (gcnew System::Windows::Forms::ListBox());
			   this->loadButton = (gcnew System::Windows::Forms::Button());
			   this->defragButton = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // File_Names_Address
			   // 
			   this->File_Names_Address->FormattingEnabled = true;
			   this->File_Names_Address->Location = System::Drawing::Point(12, 12);
			   this->File_Names_Address->Name = L"File_Names_Address";
			   this->File_Names_Address->Size = System::Drawing::Size(393, 121);
			   this->File_Names_Address->TabIndex = 0;
			   this->File_Names_Address->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm6::listBoxBeforeDefrag_SelectedIndexChanged);
			   // 
			   // Available_Addresses
			   // 
			   this->Available_Addresses->FormattingEnabled = true;
			   this->Available_Addresses->Location = System::Drawing::Point(12, 148);
			   this->Available_Addresses->Name = L"Available_Addresses";
			   this->Available_Addresses->Size = System::Drawing::Size(393, 121);
			   this->Available_Addresses->TabIndex = 1;
			   // 
			   // loadButton
			   // 
			   this->loadButton->Location = System::Drawing::Point(20, 308);
			   this->loadButton->Name = L"loadButton";
			   this->loadButton->Size = System::Drawing::Size(120, 30);
			   this->loadButton->TabIndex = 2;
			   this->loadButton->Text = L"Load File System";
			   this->loadButton->Click += gcnew System::EventHandler(this, &MyForm6::loadButton_Click);
			   // 
			   // defragButton
			   // 
			   this->defragButton->Location = System::Drawing::Point(271, 308);
			   this->defragButton->Name = L"defragButton";
			   this->defragButton->Size = System::Drawing::Size(120, 30);
			   this->defragButton->TabIndex = 3;
			   this->defragButton->Text = L"Defragment";
			   this->defragButton->Click += gcnew System::EventHandler(this, &MyForm6::defragButton_Click);
			   // 
			   // MyForm6
			   // 
			   this->ClientSize = System::Drawing::Size(417, 363);
			   this->Controls->Add(this->File_Names_Address);
			   this->Controls->Add(this->Available_Addresses);
			   this->Controls->Add(this->loadButton);
			   this->Controls->Add(this->defragButton);
			   this->Name = L"MyForm6";
			   this->Text = L"Defragmentation Viewer";
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void loadButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Clear existing items
		File_Names_Address->Items->Clear();
		Available_Addresses->Items->Clear();

		// Add header for files section
		File_Names_Address->Items->Add("=== Files with Starting Addresses ===");

		// Get file list from FileSystemManager
		map<string, int> fileList = fa->listFiles();

		// Display files with their addresses and first line of content
		for (const auto& file : fileList) {
			int address = fa->getFileAddress(file.first);  // Using the new method
			string content = fa->viewFile(file.first);
			string firstLine = content.substr(0, content.find('\n'));

			// Format exactly like your image: "File2 1000 | Content preview"
			String^ entry = gcnew String((
				file.first + " " + to_string(address) +
				" | " + firstLine).c_str());

			File_Names_Address->Items->Add(entry);
		}

		// Add header for available blocks section
		Available_Addresses->Items->Add("=== Available Memory Blocks ===");

		// Get and display available blocks in groups like your image
		vector<int> freeBlocks = memoryManager->getFreeBlocksList();
		string blockGroup;
		int blocksInGroup = 0;
		const int BLOCKS_PER_GROUP = 3; // Matches your image's 3-column display

		for (int addr : freeBlocks) {
			blockGroup += to_string(addr) + " ";
			blocksInGroup++;

			if (blocksInGroup % BLOCKS_PER_GROUP == 0) {
				Available_Addresses->Items->Add(gcnew String(("| " + blockGroup + " |").c_str()));
				blockGroup.clear();
			}
		}

		// Add any remaining blocks
		if (!blockGroup.empty()) {
			Available_Addresses->Items->Add(gcnew String(("| " + blockGroup + " |").c_str()));
		}

	}

	private: System::Void defragButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show BEFORE state header
		File_Names_Address->Items->Add("--- BEFORE DEFRAGMENTATION ---");
		Available_Addresses->Items->Add("--- BEFORE DEFRAGMENTATION ---");

		// Show current state
		loadButton_Click(sender, e);

		// Perform defragmentation
		fa->Defragmentation();

		// Add separator
		File_Names_Address->Items->Add("------------------------------");
		Available_Addresses->Items->Add("------------------------------");

		// Show AFTER state header
		File_Names_Address->Items->Add("--- AFTER DEFRAGMENTATION ---");
		Available_Addresses->Items->Add("--- AFTER DEFRAGMENTATION ---");

		// Refresh with new state
		loadButton_Click(sender, e);

		// Add status message like in your image
		File_Names_Address->Items->Add(">> Files consolidated <<");
		Available_Addresses->Items->Add(">> Free blocks merged <<");
	}



	private: System::Void listBoxBeforeDefrag_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (File_Names_Address->SelectedIndex > 0) { // Skip headers
			String^ selected = File_Names_Address->SelectedItem->ToString();
			if (selected->Contains("|")) {
				// Extract filename
				String^ filename = selected->Substring(0, selected->IndexOf(" "));

				// Get full content
				string content = fa->viewFile(marshal_as<string>(filename));

				// Show content preview
				MessageBox::Show(gcnew String(content.c_str()),
					"File Content: " + filename,
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			}
		}
	}
	};
}