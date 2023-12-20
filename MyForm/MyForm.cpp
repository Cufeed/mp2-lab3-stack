#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThread]
//void Main(array<String^>^ args)
int main(cli::array < String^>^ args)
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm::MyForm form;
	Application::Run(% form);
}