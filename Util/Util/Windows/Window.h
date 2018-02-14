#pragma once

#include "../Basic.h"
#include "Base.h"

#include <Windows.h>

namespace CAN
{
	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	class Window : implements Object
	{
	private:
		HWND mhWnd;
		uint miResX, miResY;
		wstring mstrTitle;

	public:
		Window() {}

		bool Create(const wstring& strTitle, const uint iResX, const uint iResY);

		bool RegisterWindowClass();
	};

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			HGDIOBJ original = NULL;
			RECT rect = { 10, 10, 200, 300 };
			original = SelectObject(hdc, GetStockObject(DC_PEN));
			SelectObject(hdc, GetStockObject(BLACK_PEN));
			SelectObject(hdc, GetStockObject(DC_PEN));
			SelectObject(hdc, GetStockObject(DC_BRUSH));
			SetDCBrushColor(hdc, RGB(255, 0, 0));
			SetDCPenColor(hdc, RGB(0, 0, 255));
			SetDCBrushColor(hdc, RGB(0, 255, 0));
			Rectangle(hdc, 300, 150, 500, 300);
			EndPaint(hWnd, &ps);
		}
		break;
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		break;
		}
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

}