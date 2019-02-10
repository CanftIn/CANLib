/*
    CAN_LIB: CanftIn's Library
    Module: CONFIG
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at http://www.canftin.com
	MIT licence
*/

#ifndef CAN_CONFIG
#define CAN_CONFIG

// Operating system detection
#if(defined(__linux) || defined(__unix) || defined(__posix) || \
    defined(__LINUX__) || defined(__linux__))
#   define CAN_OS_LINUX 1
#elif(defined(_WIN64) || defined(_WIN32) || defined(__CYGWIN32__) || \
      defined(__MINGW32__))
/// @macro This macro is defined if the current OS is Windows.
#   define CAN_OS_WINDOWS 1
#elif(defined(MACOSX) || defined(__DARWIN__) || defined(__APPLE__))
/// @macro This macro is defined if the current OS is Mac.
#   define CAN_OS_MAC 1
#else
/// @macro This macro is defined if the current OS is unknown.
#   define CAN_OS_UNKNOWN 1
#endif

// Architecture detection
#if(defined(WIN_32) || defined(__i386__) || defined(i386) || defined(__x86__))
/// @macro This macro is defined if the current architecture is 32 bit.
#define CAN_ARCH_32 1
#elif(defined(__amd64) || defined(__amd64__) || defined(__x86_64) || \
      defined(__x86_64__) || defined(_M_X64) || defined(__ia64__) || \
      defined(_M_IA64))
/// @macro This macro is defined if the current architecture is 64 bit.
#   define CAN_ARCH_64 1
#else
/// @macro This macro is defined if the current architecture is unknown.
#   define CAN_ARCH_UNKNOWN 1
#endif

// Compiler detection
#if(defined(__clang__))
/// @macro This macro is defined if the current compiler is clang.
#   define CAN_COMPILER_CLANG 1
#elif(defined(__GNUC__))
/// @macro This macro is defined if the current compiler is gcc.
#   define CAN_COMPILER_GCC 1
#else
/// @macro This macro is defined if the current compiler is unknown.
#   define CAN_COMPILER_UNKNOWN 1
#endif

// Debug mode detection
#if !defined(NDEBUG)
#   define CAN_DEBUG 1
#endif

// Standard library detection
#if defined(_LIBCPP_VERSION)
#   define CAN_STDLIB_LIBCXX 1
#elif defined(__GLIBCXX__)
#   define CAN_STDLIB_LIBSTDCXX 1
#else
#   define CAN_STDLIB_UNKNOWN 1
#endif

#endif