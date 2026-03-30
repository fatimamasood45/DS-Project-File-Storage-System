#pragma once

#include "Header.h"
#include <msclr/marshal_cppstd.h>

namespace ProGui {

    using namespace System;
    using namespace System::Drawing;
    using namespace System::Windows::Forms;

    public ref class MyForm7 : public Form
    {
    private:
        FileSystemManager* fsManager;
        Panel^ panelFileTable;
        Panel^ panelFreeBlocks;
        Panel^ panelFileData;
        Label^ labelHeader1, ^ labelHeader2, ^ labelHeader3;
        DataGridView^ dataGridViewFiles;
        ListBox^ listBoxFreeBlocks;
        RichTextBox^ richTextBoxData;

    public:
        MyForm7(FileSystemManager* manager)
        {
            fsManager = manager;
            InitializeComponents();
            LoadData();
        }

        void InitializeComponents()
        {
            // Main form setup
            this->Text = "File System Structure Visualizer";
            this->Size = Drawing::Size(900, 600);
            this->StartPosition = FormStartPosition::CenterScreen;

            // Panel 1: File Table (1MB)
            panelFileTable = gcnew Panel();
            panelFileTable->BackColor = Color::LightBlue;
            panelFileTable->BorderStyle = BorderStyle::FixedSingle;
            panelFileTable->Size = Drawing::Size(300, 500);
            panelFileTable->Location = Point(10, 50);

            labelHeader1 = gcnew Label();
            labelHeader1->Text = "File Table (1MB)";
            labelHeader1->Location = Point(10, 10);

            dataGridViewFiles = gcnew DataGridView();
            dataGridViewFiles->Size = Drawing::Size(280, 450);
            dataGridViewFiles->Location = Point(10, 40);
            dataGridViewFiles->ReadOnly = true;
            dataGridViewFiles->Columns->Add("FileName", "File Name");
            dataGridViewFiles->Columns->Add("StartAddress", "Start Address");

            // Panel 2: Free Blocks (1MB)
            panelFreeBlocks = gcnew Panel();
            panelFreeBlocks->BackColor = Color::LightGreen;
            panelFreeBlocks->BorderStyle = BorderStyle::FixedSingle;
            panelFreeBlocks->Size = Drawing::Size(250, 500);
            panelFreeBlocks->Location = Point(320, 50);

            labelHeader2 = gcnew Label();
            labelHeader2->Text = "Free Blocks (1MB)";
            labelHeader2->Location = Point(320, 10);

            listBoxFreeBlocks = gcnew ListBox();
            listBoxFreeBlocks->Size = Drawing::Size(230, 450);
            listBoxFreeBlocks->Location = Point(330, 40);

            // Panel 3: File Data (8MB)
            panelFileData = gcnew Panel();
            panelFileData->BackColor = Color::LightSalmon;
            panelFileData->BorderStyle = BorderStyle::FixedSingle;
            panelFileData->Size = Drawing::Size(300, 500);
            panelFileData->Location = Point(580, 50);

            labelHeader3 = gcnew Label();
            labelHeader3->Text = "File Data (8MB)";
            labelHeader3->Location = Point(580, 10);

            richTextBoxData = gcnew RichTextBox();
            richTextBoxData->Size = Drawing::Size(280, 450);
            richTextBoxData->Location = Point(590, 40);
            richTextBoxData->ReadOnly = true;

            // Add controls to form
            this->Controls->Add(panelFileTable);
            this->Controls->Add(panelFreeBlocks);
            this->Controls->Add(panelFileData);
            this->Controls->Add(labelHeader1);
            this->Controls->Add(labelHeader2);
            this->Controls->Add(labelHeader3);
            panelFileTable->Controls->Add(dataGridViewFiles);
            panelFreeBlocks->Controls->Add(listBoxFreeBlocks);
            panelFileData->Controls->Add(richTextBoxData);
        }

        void LoadData()
        {
            // Load file table data
            auto files = fsManager->listFiles();
            for each (auto pair in files)
            {
                dataGridViewFiles->Rows->Add(
                    gcnew String(pair.first.c_str()),
                    pair.second.ToString());
            }

            // Load free blocks (you'll need to expose this from your MemoryAllocator)
            // This is just an example - implement based on your actual free block tracking
            for (int i = 0; i < 20; i++) // Example: show first 20 free blocks
            {
                listBoxFreeBlocks->Items->Add((2048 + i * 1024).ToString()); // Starting from 2MB
            }

            // Load sample file data
            richTextBoxData->Text = "File 1:1000 - This is file 1 data\n"
                "File 2:2024 - This is file 2 data\n"
                "...\n"
                "Continuation addresses shown here";
        }
    private: System::Void InitializeComponent() {
        this->SuspendLayout();
        // 
        // MyForm7
        // 
        this->ClientSize = System::Drawing::Size(304, 305);
        this->Name = L"MyForm7";
        this->ResumeLayout(false);
    }
};
}