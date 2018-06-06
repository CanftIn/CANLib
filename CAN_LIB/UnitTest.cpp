#include "UnitTest.hpp"

/*
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
*/

class cppunit : public UnitTest
{
public:
    void single_test()
    {
        CHECK(2 + 2, 4);

        CHECK_BOOL(2 + 2 == 4);

        CHECK_STR("ab", "ab");

        error_test();
    }

    void error_test()
    {
        //CHECK_STR("shuaibi", "ab");
    }
};

int main()
{
    cppunit test;
    test.run();

    return 0;
}

/**
    F
    ==================================================
    FAIL: single_test
    --------------------------------------------------
    File "UnitTest.cpp", line 26 in single_test
    Checking 2 + 2 == 5
    Error: "4" ! = "5"

    --------------------------------------------------
    Ran 1 checks in 0s

    FAILED (failures=1)
*/