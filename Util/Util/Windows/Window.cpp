#include "Window.h"
#include "Application.h"

namespace CAN
{
	const wchar_t* Application::WinClassName = L"CANWinClass";

	bool Window::Create(const wstring& strTitle,
		const uint iWidth,
		const uint iHeight)
	{
		mstrTitle = strTitle;
		miWidth = iWidth;
		miHeight = iHeight;

		if (!RegisterWindowClass())
			return false;

		DWORD winStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
		DWORD winStyleEX = WS_EX_CLIENTEDGE;

		RECT rect = { 0, 0, miWidth, miHeight };
		AdjustWindowRectEx(&rect, winStyle, NULL, winStyleEX);

		mhWnd = ::CreateWindowEx(
			winStyleEX,
			Application::WinClassName,
			mstrTitle.data(),
			winStyle,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			rect.right - rect.left,
			rect.bottom - rect.top,
			GetDesktopWindow(),
			NULL,
			Application::GetInstanceHandle(),
			NULL
		);
		if (!mhWnd)
			return false;
		return true;
	}

	void Window::Destory()
	{
		mReleaseEvent.Invoke(this, EventArgs());
		::UnregisterClass(Application::WinClassName, Application::GetInstanceHandle());
	}

	bool Window::RegisterWindowClass()
	{
		WNDCLASSEX winClass;
		winClass.cbSize = sizeof(WNDCLASSEX);
		winClass.style = CS_OWNDC;
		winClass.lpfnWndProc = WndProc;
		winClass.cbClsExtra = 0;
		winClass.cbWndExtra = 0;
		winClass.hInstance = (HINSTANCE)GetModuleHandle(NULL);
		winClass.hIcon = LoadIcon(0, IDI_APPLICATION);
		winClass.hCursor = LoadCursor(0, IDC_ARROW);
		winClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		winClass.lpszMenuName = 0;
		winClass.lpszClassName = Application::WinClassName;
		winClass.hIconSm = LoadIcon(0, IDI_APPLICATION);

		if (!::RegisterClassEx(&winClass))
			return false;

		return true;
	}

	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
		return 0;
	}
}