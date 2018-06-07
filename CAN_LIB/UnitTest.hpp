#ifndef UNITTEST_HPP
#define UNITTEST_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>


/************************************************/
// Terminal Colors
#define NONE                "\e[0m"
#define L_RED               system("color 04"); 
#define L_GREEN             "\e[1;32m"
#define BOLD                "\e[1m"
#define L_BLUE              "\e[1;34m"
/************************************************/


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

#define GENERATE_CLASS_NAME(CLASS, FUNCTION) CLASS##FUNCTION

#define ADDTEST(parent_class, func_name) \
class GENERATE_CLASS_NAME(parent_class, func_name) : public parent_class \
{ \
public: \
    GENERATE_CLASS_NAME(parent_class, func_name)() {} \
    void testBody(); \
    void check() \
    { \
        std::cout << "Case " << UnitTest::getInstance()->getInvokeCount() << \
            " " << #parent_class << "::" << #func_name << std::endl; \
    } \
    void status() \
    { \
        std::cout << std::endl; \
    } \
private: \
    static const unsigned long addInstanceIndex; \
    std::vector<const char*> msgs; \
    void addMsg(const char* msg) {msgs.push_back(msg);} \
    GENERATE_CLASS_NAME(parent_class, func_name) \
        (const GENERATE_CLASS_NAME(parent_class, func_name)&); \
    GENERATE_CLASS_NAME(parent_class, func_name)& \
        operator=(const GENERATE_CLASS_NAME(parent_class, func_name)&); \
};\
const unsigned long GENERATE_CLASS_NAME(parent_class, func_name)::addInstanceIndex = \
    UnitTest::getInstance()->addTest(new GENERATE_CLASS_NAME(parent_class, func_name)); \
void GENERATE_CLASS_NAME(parent_class, func_name)::testBody()


class TestSuite
{
public:
    virtual void setup() {}
    virtual void teardown() {}
    virtual void testBody() = 0;
    virtual void check() = 0;
    virtual void status() = 0;
};

class UnitTest
{
private:
    UnitTest() {}
    UnitTest(const UnitTest&);
    UnitTest& operator=(const UnitTest&);

public:
    static UnitTest* getInstance()
    {
        static UnitTest instance;
        return &instance;
    }

    void run()
    {
        std::cout << "size of test cases: " << testCases.size() << std::endl;
        for (int i = 0; i < testCases.size(); ++i) 
        {
            testCases[i]->check();
            testCases[i]->setup();
            testCases[i]->testBody();
            testCases[i]->teardown();
            testCases[i]->status();
        }
    }

    void tick() { invokeCount++; }

    int getInvokeCount() { return invokeCount; }

    unsigned long addTest(TestSuite *testCase)
    {
        testCases.push_back(testCase);
        return testCases.size();
    }

private:
    std::vector<TestSuite*> testCases;
    int invokeCount = 1;

// Test Macro
#define eq(a, b) \
    if ((a) == (b)) std::cout << "equal" << std::endl; \
    else \
        std::cout << "error" << std::endl;
};

/***********************************************x
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
*/
/************************************************/

#endif