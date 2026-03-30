#pragma once
#include "Header.h"
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

namespace ProGui {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class MyForm8 : public Form {
    private:
        FileSystemManager* fs;
        DataGridView^ dgvFiles;
        ListBox^ lbFreeBlocks;
        RichTextBox^ rtbData;  // This matches your declaration

    public:
        MyForm8(FileSystemManager* manager) : fs(manager) {
            InitializeComponent();
            LoadVisualizationData();

            // Connect the selection changed event
         //   dgvFiles->SelectionChanged += gcnew EventHandler(this, &MyForm8::OnFileSelected);
        }

    private:
        void InitializeComponent() {
            // ... [Keep all your existing initialization code exactly as is] ...
        }

        void LoadVisualizationData() {
            // ... [Keep your existing LoadVisualizationData code] ...
        }

    private:
        void DisplayFileContents(int startAddress) {
            rtbData->Clear();  // Use rtbData instead of rtbFileData
            auto blocks = fs->getFiles().getFile(startAddress);

            for (size_t i = 0; i < blocks.size(); i++) {
                // Current block
                rtbData->AppendText(
                    "BLOCK 0x" + blocks[i].address.ToString("X4") + ":\n" +
                    gcnew String(blocks[i].data.c_str()) + "\n");

                // Continuation arrow (except for last block)
                if (i < blocks.size() - 1) {
                    rtbData->AppendText(
                        "? Continues at 0x" + blocks[i + 1].address.ToString("X4") + "\n\n");
                }
            }
        }

        // Add this new event handler
        void OnFileSelected(Object^ sender, EventArgs^ e) {
            if (dgvFiles->SelectedRows->Count > 0) {
               // String^ addrStr = safe_cast<String^>(dgvFiles->SelectedRows[0]->Cells[1]->Value);
                //int address = Int32::Parse(addrStr->Substring(2), System::Globalization::NumberStyles::HexNumber);
                //DisplayFileContents(address);
            }
        }
    };
}