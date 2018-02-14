#pragma once

#include "../Basic.h"
#include "Base.h"

#include <Windows.h>

namespace CAN
{
	class Application : implements Object
	{
	private:
		static HINSTANCE InstHandle;

	public:
		static const wchar_t* WinClassName;

	public:
		static HINSTANCE GetInstanceHandle()
		{
			return InstHandle;
		}
	};
}