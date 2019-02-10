/*
    CAN_LIB: CanftIn's Library
    Module: DELEGATE
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at http://www.canftin.com
	MIT licence
*/

#ifndef CAN_DELEGATE_H
#define CAN_DELEGATE_H

#include "Basic.h"

namespace CAN
{
    template<typename TReturn, typename... TArgs>
    class Delegate;

    namespace detail
    {
        template<typename TReturn, typename... TArgs>
        struct DelegateHelper
        {
            inline static auto exec(
                Delegate<TReturn(TArgs...)>& mDelegate, TArgs... mArgs
            )
            {
                std::vector<TReturn> result;
                result.reserve(mDelegate.funcs.size());
                for(const auto& f : mDelegate.funcs)
                    result.emplace_back(f(mArgs...));
                return result;
            }
        };

        template<typename... TArgs>
        struct DelegateHelper<void, TArgs...>
        {
            inline static void exec(
                Delegate<void(TArgs...)>& mDelegate, TArgs... mArgs
            )
            {
                for(const auto& f : mDelegate.funcs) 
                    f(mArgs...);
            }
        };
    }

    template<typename TReturn, typename... TArgs>
    class Delegate<TReturn(TArgs...)>
    {
        template<typename, typename...>
        friend struct detail::DelegateHelper;
    
    private:
        using FuncType = std::function<TReturn(TArgs...)>;
        std::vector<FuncType> funcs;

    public:
        /// @brief Add function to the delegate
        /// @param mFunc type can be std::function or lambda
        template<typename T>
        inline auto& operator+=(const T& mFunc)
        {
            funcs.emplace_back(mFunc);
            return *this;
        }

        /// #brief Call all the functions in the delegate
        /// @code
        /// delegate();
        /// #endcode
        /// @return void or std::vector
        inline auto operator()(TArgs... mArgs)
        {
            return detail::DelegateHelper<TReturn, TArgs...>::exec(*this, mArgs...);
        }

        inline void clear() noexcept
        {
            funcs.clear();
        }

        inline bool isEmpty() const noexcept
        {
            return funcs.empty();
        }
    };
}

#endif // !DELEGATE_H


