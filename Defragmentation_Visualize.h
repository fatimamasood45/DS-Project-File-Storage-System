#pragma once
#include "Header.h"
#include <msclr/marshal_cppstd.h>

namespace ProGui {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Defragmentation_Visualize : public System::Windows::Forms::Form
    {
    public:
        Defragmentation_Visualize(FileSystemManager* manager)
        {
            fsManager = manager;
            fsManager->Defragmentation();
            InitializeComponent();
            LoadPortion1Data();
            LoadPortion2Data();
            LoadPortion3Data();
        }

    protected:
        ~Defragmentation_Visualize()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::ListBox^ listBox1;
    protected:
    private: System::Windows::Forms::ListBox^ listBox2;
    private: System::Windows::Forms::ListBox^ listBox3;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Button^ buttonRefresh;
    private: System::Windows::Forms::Button^ buttonClose;
    private: System::Windows::Forms::Label^ labelStatus;
    private: System::Windows::Forms::Label^ label4;

    private:
        FileSystemManager* fsManager;
    private: System::Windows::Forms::Label^ label5;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->listBox1 = (gcnew System::Windows::Forms::ListBox());
            this->listBox2 = (gcnew System::Windows::Forms::ListBox());
            this->listBox3 = (gcnew System::Windows::Forms::ListBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->buttonRefresh = (gcnew System::Windows::Forms::Button());
            this->buttonClose = (gcnew System::Windows::Forms::Button());
            this->labelStatus = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // listBox1
            // 
            this->listBox1->FormattingEnabled = true;
            this->listBox1->ItemHeight = 20;
            this->listBox1->Location = System::Drawing::Point(6, 85);
            this->listBox1->Name = L"listBox1";
            this->listBox1->Size = System::Drawing::Size(332, 544);
            this->listBox1->TabIndex = 0;
            // 
            // listBox2
            // 
            this->listBox2->FormattingEnabled = true;
            this->listBox2->ItemHeight = 20;
            this->listBox2->Location = System::Drawing::Point(365, 85);
            this->listBox2->Name = L"listBox2";
            this->listBox2->Size = System::Drawing::Size(342, 544);
            this->listBox2->TabIndex = 1;
            // 
            // listBox3
            // 
            this->listBox3->FormattingEnabled = true;
            this->listBox3->HorizontalScrollbar = true;
            this->listBox3->ItemHeight = 20;
            this->listBox3->Location = System::Drawing::Point(735, 85);
            this->listBox3->Name = L"listBox3";
            this->listBox3->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->listBox3->Size = System::Drawing::Size(527, 544);
            this->listBox3->TabIndex = 2;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(12, 46);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(159, 22);
            this->label1->TabIndex = 3;
            this->label1->Text = L"File Table (1MB)";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(361, 46);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(175, 22);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Free Blocks (1MB)";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(731, 46);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(150, 22);
            this->label3->TabIndex = 5;
            this->label3->Text = L"File Data (8MB)";
            // 
            // buttonRefresh
            // 
            this->buttonRefresh->BackColor = System::Drawing::Color::Khaki;
            this->buttonRefresh->Location = System::Drawing::Point(1006, 635);
            this->buttonRefresh->Name = L"buttonRefresh";
            this->buttonRefresh->Size = System::Drawing::Size(112, 35);
            this->buttonRefresh->TabIndex = 6;
            this->buttonRefresh->Text = L"Refresh";
            this->buttonRefresh->UseVisualStyleBackColor = false;
            this->buttonRefresh->Click += gcnew System::EventHandler(this, &Defragmentation_Visualize::buttonRefresh_Click);
            // 
            // buttonClose
            // 
            this->buttonClose->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->buttonClose->Location = System::Drawing::Point(1150, 635);
            this->buttonClose->Name = L"buttonClose";
            this->buttonClose->Size = System::Drawing::Size(112, 35);
            this->buttonClose->TabIndex = 7;
            this->buttonClose->Text = L"Close";
            this->buttonClose->UseVisualStyleBackColor = false;
            this->buttonClose->Click += gcnew System::EventHandler(this, &Defragmentation_Visualize::buttonClose_Click);
            // 
            // labelStatus
            // 
            this->labelStatus->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->labelStatus->Location = System::Drawing::Point(140, 635);
            this->labelStatus->Name = L"labelStatus";
            this->labelStatus->Size = System::Drawing::Size(567, 35);
            this->labelStatus->TabIndex = 8;
            this->labelStatus->Text = L"Ready";
            this->labelStatus->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::Coral;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->ForeColor = System::Drawing::Color::Black;
            this->label4->Location = System::Drawing::Point(12, 9);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(434, 25);
            this->label4->TabIndex = 9;
            this->label4->Text = L"DEFRAGMENTED   FILE   SYSTEM   VIEW";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(5, 640);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(119, 22);
            this->label5->TabIndex = 10;
            this->label5->Text = L"Status Box: ";
            // 
            // Defragmentation_Visualize
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1274, 682);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->labelStatus);
            this->Controls->Add(this->buttonClose);
            this->Controls->Add(this->buttonRefresh);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->listBox3);
            this->Controls->Add(this->listBox2);
            this->Controls->Add(this->listBox1);
            this->Name = L"Defragmentation_Visualize";
            this->Text = L"Defragmented File System Visualization";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        void LoadPortion1Data()
        {
            try {
                listBox1->Items->Clear();
                map<string, int>& headerMap = fsManager->getHeaderFiles().getmap();

                if (headerMap.empty()) {
                    UpdateStatus("No files in File Table");
                    return;
                }

                for (const auto& entry : headerMap) {
                    String^ fileEntry = gcnew String(entry.first.c_str());
                    fileEntry += " : " + entry.second.ToString();
                    listBox1->Items->Add(fileEntry);
                }

                UpdateStatus("Loaded " + headerMap.size() + " files from File Table");
            }
            catch (Exception^ e) {
                UpdateStatus("Error loading File Table: " + e->Message);
            }
        }

        void LoadPortion2Data()
        {
            try {
                listBox2->Items->Clear();
                MemoryAllocator& memoryAllocator = fsManager->getMemoryAllocator();

                // Get free blocks from the memory allocator
                priority_queue<int, vector<int>, greater<int>> freeBlocksCopy = memoryAllocator.FreeMemory;

                if (freeBlocksCopy.empty()) {
                    UpdateStatus("No free blocks available");
                    return;
                }

                // Display free blocks
                while (!freeBlocksCopy.empty()) {
                    int address = freeBlocksCopy.top();
                    freeBlocksCopy.pop();
                    listBox2->Items->Add("Block at: " + address.ToString());
                }

                UpdateStatus("Loaded free blocks list");
            }
            catch (Exception^ e) {
                UpdateStatus("Error loading free blocks: " + e->Message);
            }
        }

        void LoadPortion3Data()
        {
            try {
                listBox3->Items->Clear();
                map<string, int>& headerMap = fsManager->getHeaderFiles().getmap();
                Files& files = fsManager->getFiles();

                if (headerMap.empty()) {
                    UpdateStatus("No files to display data for");
                    return;
                }

                for (const auto& entry : headerMap) {
                    String^ fileName = gcnew String(entry.first.c_str());
                    int address = entry.second;

                    deque<Block> fileBlocks = files.getFile(address);
                    for (size_t i = 0; i < fileBlocks.size(); i++) {
                        const Block& block = fileBlocks[i];
                        String^ blockEntry = fileName + " @ " + block.address.ToString();

                        // Check if this is the last block in the file
                        if (i == fileBlocks.size() - 1) {
                            blockEntry += " : " + gcnew String(block.data.c_str()) + " [EOF]";
                        }
                        else {
                            blockEntry += " : " + gcnew String(block.data.c_str());
                        }

                        listBox3->Items->Add(blockEntry);
                    }
                }

                UpdateStatus("Loaded file data blocks after defragmentation");
            }
            catch (Exception^ e) {
                UpdateStatus("Error loading file data: " + e->Message);
            }
        }

        void UpdateStatus(String^ message)
        {
            labelStatus->Text = DateTime::Now.ToString("HH:mm:ss") + " - " + message;
        }

    private:
        System::Void buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e)
        {
            LoadPortion1Data();
            LoadPortion2Data();
            LoadPortion3Data();
        }

        System::Void buttonClose_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Close();
        }
    };
}