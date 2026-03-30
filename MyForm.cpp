#include "MyForm.h"
using namespace::System;
using namespace::System::Windows::Forms;

void Main(cli::array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProGui::MyForm form;
	Application::Run(% form);
}
