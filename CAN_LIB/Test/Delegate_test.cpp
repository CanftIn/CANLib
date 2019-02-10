#include <iostream>
#include "../Delegate.h"

int main()
{
    int result{0};
    CAN::Delegate<void(int)> delegate;
    delegate += [&](int value) { result += value; };
    delegate += [&](int value) { result += value * 2; };
    delegate(2);
    assert(result == 6);

    CAN::Delegate<int()> delegate_r;
    delegate_r += []{ return 0; };
    delegate_r += []{ return 10; };
    delegate_r += []{ return 20; };
    auto re{delegate_r()};
   
    assert(re[0] == 0);
    assert(re[1] == 10);
    assert(re[2] == 20);

    return 0;
}