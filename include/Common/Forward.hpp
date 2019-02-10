/*
    CAN_LIB: CanftIn's Library
    Module: FORWARD
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at http://www.canftin.com
	MIT licence
*/
#ifndef CAN_FORWARD
#define CAN_FORWARD

#include "../Basic.h"

namespace CAN
{
    template<typename T>
    inline constexpr decltype(auto) forward(std::remove_reference_t<T>& mArg) noexcept
    {
        return std::forward<T>(mArg);
    }

    template<typename T>
    inline constexpr decltype(auto) forward(std::remove_reference_t<T>&& mArg) noexcept
    {
        return std::forward<T>(mArg);
    }

/// #marco perfect forward for variadic arguments
#define CAN_FORWARD(...) ::CAN::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)

#ifndef FORWARD
#define FORWARD(...) CAN_FORWARD(__VA_ARGS__)
#endif

}

#endif