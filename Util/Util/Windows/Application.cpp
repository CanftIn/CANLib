#include "Application.h"
#include "Window.h"


namespace CAN
{
	HINSTANCE Application::InstHandle = NULL;
	//const wchar_t* Application::WinClassName = _T("CANWinClass");
	Window* Application::pPrimaryWindow = nullptr;

	int Application::Run(Window* pWindow)
	{
		return 0;
	}
}