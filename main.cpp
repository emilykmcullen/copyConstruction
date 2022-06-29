#include <iostream>
#include <stdlib.h>

class Test
{
public:
    int a = -1;
    Test()
    {
        printf("Constructed\n");
    }
    
    Test(const Test& t)
    {
        this->a = t.a;
        printf("Copy constructed from l-value ref\n");
    }
    
    Test(const Test&& t)
    {
        printf("Constructed from r-value ref\n");
    };
    
    void operator=(const Test& test)
    {
        printf("Assigned\n");
        this->a = test.a;
    }
    
    void operator=(const Test&& test)
    {
        printf("Assigned rvalue\n");
        this->a = test.a;
    }
};

Test CreateTest()
{
    Test test;
    test.a = 10;
    if (rand() > 32)
    {
        test.a = -10;
    }
    return test;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Test t1;
    t1 = CreateTest();
    return t1.a;
}
