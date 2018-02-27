#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <limits>

namespace CAN
{
	namespace Constants
	{
		static struct Null {
		} CAN_NULL;

		static struct True {
			__forceinline operator bool() const { return true; }
		} CAN_TRUE;

		static struct False {
			__forceinline operator bool() const { return false; }
		} CAN_FALSE;

		static struct Emp {
		} CAN_EMP;

		static struct Full {
		} CAN_FULL;
	}

	namespace Math
	{
		static struct Zero
		{
			__forceinline operator double() const { return 0.0; }
			__forceinline operator float() const { return 0.0f; }
			__forceinline operator long long() const { return 0; }
			__forceinline operator unsigned long long() const { return 0; }
			__forceinline operator long() const { return 0; }
			__forceinline operator unsigned long() const { return 0; }
			__forceinline operator int() const { return 0; }
			__forceinline operator unsigned int() const { return 0; }
			__forceinline operator short() const { return 0; }
			__forceinline operator unsigned short() const { return 0; }
			__forceinline operator char() const { return 0; }
			__forceinline operator unsigned char() const { return 0; }
		} CAN_ZERO;

		static struct One
		{
			__forceinline operator double() const { return 1.0; }
			__forceinline operator float() const { return 1.0f; }
			__forceinline operator long long() const { return 1; }
			__forceinline operator unsigned long long() const { return 1; }
			__forceinline operator long() const { return 1; }
			__forceinline operator unsigned long() const { return 1; }
			__forceinline operator int() const { return 1; }
			__forceinline operator unsigned int() const { return 1; }
			__forceinline operator short() const { return 1; }
			__forceinline operator unsigned short() const { return 1; }
			__forceinline operator char() const { return 1; }
			__forceinline operator unsigned char() const { return 1; }
		} CAN_ONE;

		static struct NegInf
		{
			__forceinline operator double() const { return -std::numeric_limits<double>::infinity(); }
			__forceinline operator float() const { return -std::numeric_limits<float>::infinity(); }
			__forceinline operator long long() const { return std::numeric_limits<long long>::min(); }
			__forceinline operator unsigned long long() const { return std::numeric_limits<unsigned long long>::min(); }
			__forceinline operator long() const { return std::numeric_limits<long>::min(); }
			__forceinline operator unsigned long() const { return std::numeric_limits<unsigned long>::min(); }
			__forceinline operator int() const { return std::numeric_limits<int>::min(); }
			__forceinline operator unsigned int() const { return std::numeric_limits<unsigned int>::min(); }
			__forceinline operator short() const { return std::numeric_limits<short>::min(); }
			__forceinline operator unsigned short() const { return std::numeric_limits<unsigned short>::min(); }
			__forceinline operator char() const { return std::numeric_limits<char>::min(); }
			__forceinline operator unsigned char() const { return std::numeric_limits<unsigned char>::min(); }

		} CAN_NEG_INFINITY;

		static struct PosInf
		{
			__forceinline operator double() const { return std::numeric_limits<double>::infinity(); }
			__forceinline operator float() const { return std::numeric_limits<float>::infinity(); }
			__forceinline operator long long() const { return std::numeric_limits<long long>::max(); }
			__forceinline operator unsigned long long() const { return std::numeric_limits<unsigned long long>::max(); }
			__forceinline operator long() const { return std::numeric_limits<long>::max(); }
			__forceinline operator unsigned long() const { return std::numeric_limits<unsigned long>::max(); }
			__forceinline operator int() const { return std::numeric_limits<int>::max(); }
			__forceinline operator unsigned int() const { return std::numeric_limits<unsigned int>::max(); }
			__forceinline operator short() const { return std::numeric_limits<short>::max(); }
			__forceinline operator unsigned short() const { return std::numeric_limits<unsigned short>::max(); }
			__forceinline operator char() const { return std::numeric_limits<char>::max(); }
			__forceinline operator unsigned char() const { return std::numeric_limits<unsigned char>::max(); }
		} CAN_INFINITY, CAN_POS_INFINITY;


	}
}



#endif // !CONSTANTS_H_
