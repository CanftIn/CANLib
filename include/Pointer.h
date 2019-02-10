/*
    CAN_LIB: CanftIn's Library
    Module: Pointer
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at http://www.canftin.com
	MIT licence
*/

#ifndef CAN_POINTER_H
#define CAN_POINTER_H

#include "Common/Forward.hpp"

namespace CAN
{
    /// @brief wrapper of std::make_unique<T>
    template<typename T, typename... TArgs>
    inline decltype(auto) makeUPtr(TArgs&&... mArgs)
    {
        return std::make_unique<T>(FORWARD(mArgs)...);
    }

    /// @brief wrapper of std::make_shared<T>
    template<typename T, typename... TArgs>
    inline decltype(auto) makeSPtr(TArgs&&... mArgs)
    {
        return std::make_shared<T>(FORWARD(mArgs)...);
    }

    namespace Impl
    {
        /// @brief Internal functor that creates unique_ptr
        template <typename T>
        struct MakerUPtr
        {
            template <typename... TArgs>
            inline static auto make(TArgs&&... mArgs)
            {
                return std::make_unique<T>(FORWARD(mArgs)...);
            }
        };

        /// @brief Internal functor that creates shared_ptr
        template <typename T>
        struct MakerSPtr
        {
            template <typename... TArgs>
            inline static auto make(TArgs&&... mArgs)
            {
                return std::make_shared<T>(FORWARD(mArgs)...);
            }
        };
    }
}

#endif
