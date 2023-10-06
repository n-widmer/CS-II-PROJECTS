
#include "stack.hpp"
#include <cassert>
#include <iostream>


int main ()
{
    {
        stack<int> test;
        test.push(1);
        
        stack<int> two;
        
        two = test;
        
        assert(test.Empty() == false);
        assert(test.top() == 1);
        
        assert(two.Empty() == false);
        assert(two.top() == 1);
    }

        std::cout << "-->>TESTING COMPLETE FOR ASSIGN <<--" << std::endl;
    return 0;
}