#ifndef UNITTEST_HPP
#define UNITTEST_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>


/************************************************/
// static test case
#define TEST_CASE(Name) \
    extern void test_case_function_##Name(void); \
    class Test_Case_Class_##Name \
    { \
    public: \
        Test_Case_Class_##Name() \
        { \
            std::cout << #Name << std::endl; \
            test_case_function_##Name(); \
        } \
    } test_case_instance_##Name; \
    void test_case_function_##Name(void)

/************************************************/


/************************************************/
// dynamic test case
class UnitTest
{
public:
    UnitTest() : checks(0), fails(0) {}

    template<typename T>
    void check(T a, T b, const std::string& stra, const std::string& strb, 
            const std::string& file, int line, const std::string& func)
    {
        checks++;
        if(a == b)
        {
            std::cout << "T";
            return ;
        }
        fails++;
        std::cout << "F";
        show_fail(stra, strb, file, line, func);
        serr << "  Error: \"" << a << "\" ! = \"" << b << "\"" << std::endl << std::endl;
    }

    void show_fail(const std::string& stra, const std::string& strb, 
            const std::string& file, int line, const std::string& func) 
    {
        serr << "==================================================" << std::endl;
        serr << "FAIL: " << func << std::endl;
        serr << "--------------------------------------------------" << std::endl;
        serr << "File \"" << file << "\", line " << line << " in " << func << std::endl;
        serr << "  Checking " << stra << " == " << strb << std::endl;
    }

    virtual void single_test() {}

    int status() 
    {
        std::cout << std::endl; 
        if (fails) 
            std::cout << serr.str();
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "Ran " << checks << " checks in " << double(clock()) / CLOCKS_PER_SEC << "s" << std::endl << std::endl;
        if (fails) 
            std::cout << "FAILED (failures=" << fails << ")";
        else 
            std::cout << "OK" << std::endl;
        return fails > 0;
    }

    int run()
    {
        single_test();
        return status();
    }

#define CHECK(A, B) check<long long>(A, B, #A, #B, __FILE__, __LINE__, __FUNCTION__);
#define CHECK_BOOL(A) check<bool>(A, true, #A, "TRUE", __FILE__, __LINE__, __FUNCTION__);
#define CHECK_STR(A, B) check<const std::string&>(A, B, #A, #B, __FILE__, __LINE__, __FUNCTION__);

public:
    int checks;
    int fails;
    std::ostringstream serr;
    std::istringstream *in;
};

/************************************************/

#endif