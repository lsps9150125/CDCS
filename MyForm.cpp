#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();


	Application::SetCompatibleTextRenderingDefault(false);

	CDCS::MyForm form;
	Application::Run(%form);
}