/*
    CAN_LIB: CanftIn's Library
    Module: Basic
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#ifndef CAN_BASIC_H
#define CAN_BASIC_H

// C++ support
#include <cstdio>
#include <malloc.h>
#include <cassert>
#include <cmath>
#include <cfloat>
#include <fstream>

// STL include files
#include <string>
using std::string;
using std::wstring;
#include <vector>
using std::vector;
#include <algorithm>
#include <functional>
#include <type_traits>
#include <memory>
#include <limits>
#include <chrono>
using std::min;
using std::max;
using std::swap;
using std::sort;

#define L_(x) L__(x)
#define L__(x) L ## x

namespace CAN
{
	typedef unsigned int	 uint;
	typedef unsigned char	 byte;
	typedef unsigned long	 dword;
	typedef			 __int8	 int8;
	typedef unsigned __int8	 uint8;
	typedef			 __int16 int16;
	typedef unsigned __int16 uint16;
	typedef			 __int32 int32;
	typedef unsigned __int32 uint32;
	typedef			 __int64 int64;
	typedef unsigned __int64 uint64;


    /************************************************
     * NoCopyable
     ************************************************/
    class NoCopyable
    {
    public:
        NoCopyable();
    private:
        NoCopyable(NoCopyable&);
        NoCopyable& operator = (const NoCopyable&);
    };

    /************************************************
     * Object
     ************************************************/
    class Object
    {
    public:
        virtual ~Object() {}
    };

    
}


#endif // !CAN_BASIC_H