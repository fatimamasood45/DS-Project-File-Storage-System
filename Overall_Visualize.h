//
//
//#pragma once
//#include "Header.h"
//#include <msclr/marshal_cppstd.h>
//
//namespace ProGui {
//
//    using namespace System;
//    using namespace System::ComponentModel;
//    using namespace System::Collections;
//    using namespace System::Windows::Forms;
//    using namespace System::Data;
//    using namespace System::Drawing;
//
//    /// <summary>
//    /// Summary for Overall_Visualize
//    /// </summary>
//    public ref class Overall_Visualize : public System::Windows::Forms::Form
//    {
//    public:
//        Overall_Visualize(FileSystemManager* manager)
//        {
//            fsManager = manager;
//            InitializeComponent();
//            LoadPortion1Data();
//            LoadPortion2Data();
//            LoadPortion3Data();
//        }
//
//    protected:
//        /// <summary>
//        /// Clean up any resources being used.
//        /// </summary>
//        ~Overall_Visualize()
//        {
//            if (components)
//            {
//                delete components;
//            }
//        }
//    private: System::Windows::Forms::ListBox^ listBox1;
//    protected:
//    private: System::Windows::Forms::ListBox^ listBox2;
//    private: System::Windows::Forms::ListBox^ listBox3;
//    private: System::Windows::Forms::Label^ label1;
//    private: System::Windows::Forms::Label^ label2;
//    private: System::Windows::Forms::Label^ label3;
//    private: System::Windows::Forms::Button^ buttonRefresh;
//    private: System::Windows::Forms::Button^ buttonClose;
//    private: System::Windows::Forms::Label^ labelStatus;
//
//    private:
//        FileSystemManager* fsManager;
//    private: System::Windows::Forms::Label^ label4;
//
//    private:
//        /// <summary>
//        /// Required designer variable.
//        /// </summary>
//        System::ComponentModel::Container^ components;
//
//#pragma region Windows Form Designer generated code
//        /// <summary>
//        /// Required method for Designer support - do not modify
//        /// the contents of this method with the code editor.
//        /// </summary>
//        void InitializeComponent(void)
//        {
//            this->listBox1 = (gcnew System::Windows::Forms::ListBox());
//            this->listBox2 = (gcnew System::Windows::Forms::ListBox());
//            this->listBox3 = (gcnew System::Windows::Forms::ListBox());
//            this->label1 = (gcnew System::Windows::Forms::Label());
//            this->label2 = (gcnew System::Windows::Forms::Label());
//            this->label3 = (gcnew System::Windows::Forms::Label());
//            this->buttonRefresh = (gcnew System::Windows::Forms::Button());
//            this->buttonClose = (gcnew System::Windows::Forms::Button());
//            this->labelStatus = (gcnew System::Windows::Forms::Label());
//            this->label4 = (gcnew System::Windows::Forms::Label());
//            this->SuspendLayout();
//            // 
//            // listBox1
//            // 
//            this->listBox1->FormattingEnabled = true;
//            this->listBox1->ItemHeight = 20;
//            this->listBox1->Location = System::Drawing::Point(6, 58);
//            this->listBox1->Name = L"listBox1";
//            this->listBox1->Size = System::Drawing::Size(332, 544);
//            this->listBox1->TabIndex = 0;
//            // 
//            // listBox2
//            // 
//            this->listBox2->FormattingEnabled = true;
//            this->listBox2->ItemHeight = 20;
//            this->listBox2->Location = System::Drawing::Point(365, 58);
//            this->listBox2->Name = L"listBox2";
//            this->listBox2->Size = System::Drawing::Size(342, 544);
//            this->listBox2->TabIndex = 1;
//            this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Overall_Visualize::listBox2_SelectedIndexChanged);
//            // 
//            // listBox3
//            // 
//            this->listBox3->FormattingEnabled = true;
//            this->listBox3->ItemHeight = 20;
//            this->listBox3->Location = System::Drawing::Point(735, 58);
//            this->listBox3->Name = L"listBox3";
//            this->listBox3->Size = System::Drawing::Size(527, 544);
//            this->listBox3->TabIndex = 2;
//            // 
//            // label1
//            // 
//            this->label1->AutoSize = true;
//            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//                static_cast<System::Byte>(0)));
//            this->label1->Location = System::Drawing::Point(12, 19);
//            this->label1->Name = L"label1";
//            this->label1->Size = System::Drawing::Size(159, 22);
//            this->label1->TabIndex = 3;
//            this->label1->Text = L"File Table (1MB)";
//            // 
//            // label2
//            // 
//            this->label2->AutoSize = true;
//            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//                static_cast<System::Byte>(0)));
//            this->label2->Location = System::Drawing::Point(361, 19);
//            this->label2->Name = L"label2";
//            this->label2->Size = System::Drawing::Size(175, 22);
//            this->label2->TabIndex = 4;
//            this->label2->Text = L"Free Blocks (1MB)";
//            // 
//            // label3
//            // 
//            this->label3->AutoSize = true;
//            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//                static_cast<System::Byte>(0)));
//            this->label3->Location = System::Drawing::Point(731, 19);
//            this->label3->Name = L"label3";
//            this->label3->Size = System::Drawing::Size(150, 22);
//            this->label3->TabIndex = 5;
//            this->label3->Text = L"File Data (8MB)";
//            // 
//            // buttonRefresh
//            // 
//            this->buttonRefresh->BackColor = System::Drawing::Color::Khaki;
//            this->buttonRefresh->Location = System::Drawing::Point(990, 608);
//            this->buttonRefresh->Name = L"buttonRefresh";
//            this->buttonRefresh->Size = System::Drawing::Size(112, 35);
//            this->buttonRefresh->TabIndex = 6;
//            this->buttonRefresh->Text = L"Refresh";
//            this->buttonRefresh->UseVisualStyleBackColor = false;
//            this->buttonRefresh->Click += gcnew System::EventHandler(this, &Overall_Visualize::buttonRefresh_Click);
//            // 
//            // buttonClose
//            // 
//            this->buttonClose->BackColor = System::Drawing::SystemColors::ActiveCaption;
//            this->buttonClose->Location = System::Drawing::Point(1124, 608);
//            this->buttonClose->Name = L"buttonClose";
//            this->buttonClose->Size = System::Drawing::Size(112, 35);
//            this->buttonClose->TabIndex = 7;
//            this->buttonClose->Text = L"Close";
//            this->buttonClose->UseVisualStyleBackColor = false;
//            this->buttonClose->Click += gcnew System::EventHandler(this, &Overall_Visualize::buttonClose_Click);
//            // 
//            // labelStatus
//            // 
//            this->labelStatus->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
//            this->labelStatus->Location = System::Drawing::Point(127, 614);
//            this->labelStatus->Name = L"labelStatus";
//            this->labelStatus->Size = System::Drawing::Size(580, 38);
//            this->labelStatus->TabIndex = 8;
//            this->labelStatus->Text = L"Ready";
//            this->labelStatus->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
//            // 
//            // label4
//            // 
//            this->label4->AutoSize = true;
//            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//                static_cast<System::Byte>(0)));
//            this->label4->Location = System::Drawing::Point(2, 621);
//            this->label4->Name = L"label4";
//            this->label4->Size = System::Drawing::Size(119, 22);
//            this->label4->TabIndex = 9;
//            this->label4->Text = L"Status Box: ";
//            // 
//            // Overall_Visualize
//            // 
//            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
//            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//            this->ClientSize = System::Drawing::Size(1274, 655);
//            this->Controls->Add(this->label4);
//            this->Controls->Add(this->labelStatus);
//            this->Controls->Add(this->buttonClose);
//            this->Controls->Add(this->buttonRefresh);
//            this->Controls->Add(this->label3);
//            this->Controls->Add(this->label2);
//            this->Controls->Add(this->label1);
//            this->Controls->Add(this->listBox3);
//            this->Controls->Add(this->listBox2);
//            this->Controls->Add(this->listBox1);
//            this->Name = L"Overall_Visualize";
//            this->Text = L"File System Visualization";
//            this->Load += gcnew System::EventHandler(this, &Overall_Visualize::Overall_Visualize_Load);
//            this->ResumeLayout(false);
//            this->PerformLayout();
//
//        }
//#pragma endregion
//
//    private:
//        void LoadPortion1Data()
//        {
//            try {
//                listBox1->Items->Clear();
//                map<string, int>& headerMap = fsManager->getHeaderFiles().getmap();
//
//                if (headerMap.empty()) {
//                    UpdateStatus("No files in File Table");
//                    return;
//                }
//
//                for (const auto& entry : headerMap) {
//                    String^ fileEntry = gcnew String(entry.first.c_str());
//                    fileEntry += " : " + entry.second.ToString();
//                    listBox1->Items->Add(fileEntry);
//                }
//
//                UpdateStatus("Loaded " + headerMap.size() + " files from File Table");
//            }
//            catch (Exception^ e) {
//                UpdateStatus("Error loading File Table: " + e->Message);
//            }
//        }
//
//        void LoadPortion2Data()
//        {
//            try {
//                listBox2->Items->Clear();
//                MemoryAllocator& memoryAllocator = fsManager->getMemoryAllocator();
//
//                // Get free blocks from the memory allocator
//                priority_queue<int, vector<int>, greater<int>> freeBlocksCopy = memoryAllocator.FreeMemory;
//
//                if (freeBlocksCopy.empty()) {
//                    UpdateStatus("No free blocks available");
//                    return;
//                }
//
//                // Display free blocks
//                while (!freeBlocksCopy.empty()) {
//                    int address = freeBlocksCopy.top();
//                    freeBlocksCopy.pop();
//                    listBox2->Items->Add("Block at: " + address.ToString());
//                }
//
//                UpdateStatus("Loaded free blocks list");
//            }
//            catch (Exception^ e) {
//                UpdateStatus("Error loading free blocks: " + e->Message);
//            }
//        }
//
//        void LoadPortion3Data()
//        {
//            try {
//                listBox3->Items->Clear();
//                map<string, int>& headerMap = fsManager->getHeaderFiles().getmap();
//                Files& files = fsManager->getFiles();
//
//                if (headerMap.empty()) {
//                    UpdateStatus("No files to display data for");
//                    return;
//                }
//
//                for (const auto& entry : headerMap) {
//                    String^ fileName = gcnew String(entry.first.c_str());
//                    int address = entry.second;
//
//                    deque<Block> fileBlocks = files.getFile(address);
//                    for (const Block& block : fileBlocks) {
//                        String^ blockEntry = fileName + " @ " + block.address.ToString();
//                        blockEntry += " : " + gcnew String(block.data.c_str());
//                        listBox3->Items->Add(blockEntry);
//                    }
//                }
//
//                UpdateStatus("Loaded file data blocks");
//            }
//            catch (Exception^ e) {
//                UpdateStatus("Error loading file data: " + e->Message);
//            }
//        }
//
//        void UpdateStatus(String^ message)
//        {
//            labelStatus->Text = DateTime::Now.ToString("HH:mm:ss") + " - " + message;
//        }
//
//    private:
//        System::Void listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
//        {
//            // Optional: Add functionality when a free block is selected
//        }
//
//        System::Void Overall_Visualize_Load(System::Object^ sender, System::EventArgs^ e)
//        {
//            // Initial load is handled in constructor
//        }
//
//        System::Void buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e)
//        {
//            LoadPortion1Data();
//            LoadPortion2Data();
//            LoadPortion3Data();
//        }
//
//        System::Void buttonClose_Click(System::Object^ sender, System::EventArgs^ e)
//        {
//            this->Close();
//        }
//    };
//}



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

    /// <summary>
    /// Summary for Overall_Visualize
    /// </summary>
    public ref class Overall_Visualize : public System::Windows::Forms::Form
    {
    public:
        Overall_Visualize(FileSystemManager* manager)
        {
            fsManager = manager;
            InitializeComponent();
            LoadPortion1Data();
            LoadPortion2Data();
            LoadPortion3Data();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Overall_Visualize()
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

    private:
        FileSystemManager* fsManager;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
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
            this->SuspendLayout();
            // 
            // listBox1
            // 
            this->listBox1->FormattingEnabled = true;
            this->listBox1->ItemHeight = 20;
            this->listBox1->Location = System::Drawing::Point(6, 58);
            this->listBox1->Name = L"listBox1";
            this->listBox1->Size = System::Drawing::Size(332, 544);
            this->listBox1->TabIndex = 0;
            // 
            // listBox2
            // 
            this->listBox2->FormattingEnabled = true;
            this->listBox2->ItemHeight = 20;
            this->listBox2->Location = System::Drawing::Point(365, 58);
            this->listBox2->Name = L"listBox2";
            this->listBox2->Size = System::Drawing::Size(342, 544);
            this->listBox2->TabIndex = 1;
            this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Overall_Visualize::listBox2_SelectedIndexChanged);
            // 
            // listBox3
            // 
            this->listBox3->FormattingEnabled = true;
            this->listBox3->HorizontalScrollbar = true;
            this->listBox3->ItemHeight = 20;
            this->listBox3->Location = System::Drawing::Point(735, 58);
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
            this->label1->Location = System::Drawing::Point(12, 19);
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
            this->label2->Location = System::Drawing::Point(361, 19);
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
            this->label3->Location = System::Drawing::Point(731, 19);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(150, 22);
            this->label3->TabIndex = 5;
            this->label3->Text = L"File Data (8MB)";
            // 
            // buttonRefresh
            // 
            this->buttonRefresh->BackColor = System::Drawing::Color::Khaki;
            this->buttonRefresh->Location = System::Drawing::Point(365, 608);
            this->buttonRefresh->Name = L"buttonRefresh";
            this->buttonRefresh->Size = System::Drawing::Size(112, 35);
            this->buttonRefresh->TabIndex = 6;
            this->buttonRefresh->Text = L"Refresh";
            this->buttonRefresh->UseVisualStyleBackColor = false;
            this->buttonRefresh->Click += gcnew System::EventHandler(this, &Overall_Visualize::buttonRefresh_Click);
            // 
            // buttonClose
            // 
            this->buttonClose->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->buttonClose->Location = System::Drawing::Point(483, 608);
            this->buttonClose->Name = L"buttonClose";
            this->buttonClose->Size = System::Drawing::Size(112, 35);
            this->buttonClose->TabIndex = 7;
            this->buttonClose->Text = L"Close";
            this->buttonClose->UseVisualStyleBackColor = false;
            this->buttonClose->Click += gcnew System::EventHandler(this, &Overall_Visualize::buttonClose_Click);
            // 
            // labelStatus
            // 
            this->labelStatus->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->labelStatus->Location = System::Drawing::Point(6, 608);
            this->labelStatus->Name = L"labelStatus";
            this->labelStatus->Size = System::Drawing::Size(353, 35);
            this->labelStatus->TabIndex = 8;
            this->labelStatus->Text = L"Ready";
            this->labelStatus->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // Overall_Visualize
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1274, 655);
            this->Controls->Add(this->labelStatus);
            this->Controls->Add(this->buttonClose);
            this->Controls->Add(this->buttonRefresh);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->listBox3);
            this->Controls->Add(this->listBox2);
            this->Controls->Add(this->listBox1);
            this->Name = L"Overall_Visualize";
            this->Text = L"File System Visualization";
            this->Load += gcnew System::EventHandler(this, &Overall_Visualize::Overall_Visualize_Load);
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
                        String^ blockEntry = String::Format("{0} @ {1}", fileName, block.address);

                        // Process block data
                        string data = block.data;
                        bool isLastBlock = (i == fileBlocks.size() - 1);
                        bool hasContinuation = false;
                        int nextAddress = -1;

                        // Check for continuation address (for non-last blocks)
                        if (!isLastBlock) {
                            size_t lastSpace = data.rfind(' ');
                            if (lastSpace != string::npos) {
                                string possibleAddress = data.substr(lastSpace + 1);
                                try {
                                    nextAddress = stoi(possibleAddress);
                                    // Validate if this is actually a continuation address
                                    if (nextAddress > 0 && (i + 1 < fileBlocks.size()) &&
                                        fileBlocks[i + 1].address == nextAddress) {
                                        hasContinuation = true;
                                        data = data.substr(0, lastSpace);
                                    }
                                }
                                catch (...) {
                                    // Not a valid address, treat as normal data
                                }
                            }
                        }

                        // Handle EOF marker for last block
                        if (isLastBlock && !data.empty() && data.back() == '\0') {
                            data = data.substr(0, data.size() - 1);
                            blockEntry += " : " + gcnew String(data.c_str()) + " [EOF]";
                        }
                        else if (hasContinuation) {
                            blockEntry += String::Format(" : {0} [Next: {1}]",
                                gcnew String(data.c_str()), nextAddress);
                        }
                        else {
                            blockEntry += " : " + gcnew String(data.c_str());
                            if (isLastBlock) {
                                blockEntry += " [EOF]";
                            }
                        }

                        // Add visual indicator if blocks are non-contiguous
                        if (i > 0 && fileBlocks[i].address != fileBlocks[i - 1].address + BLOCK_SIZE) {
                            blockEntry += " [Fragmented]";
                        }

                        listBox3->Items->Add(blockEntry);
                    }
                }

                UpdateStatus(String::Format("Loaded {0} files with data blocks", headerMap.size()));
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
        System::Void listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            // Optional: Add functionality when a free block is selected
        }

        System::Void Overall_Visualize_Load(System::Object^ sender, System::EventArgs^ e)
        {
            // Initial load is handled in constructor
        }

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