#include "UnitTest.hpp"

#include <iostream>

template<class T1, class T2> struct StaticTypeCheckEQ;
template<class T> struct StaticTypeCheckEQ<T, T> {};

template<bool B, class T> struct _EnableIf;
template<class T> struct _EnableIf<true, T> { typedef T type; };

template<bool B, class T>
using EnableIf = typename _EnableIf<B, T>::type;


TEST_CASE(EnableIf)
{
    struct T;
    StaticTypeCheckEQ<EnableIf<true, T>, T>();
}

int main()
{}