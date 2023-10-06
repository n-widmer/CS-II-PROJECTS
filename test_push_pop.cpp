

//  
//
//  Tests: Default Constructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"

//===========================================================================
int main ()
{
    {
        stack<int> test;
        test.push(5);
        test.pop();
        assert(test.Empty() == true); 
    }  
    
    {
        stack<int> test;
        test.push(5);
        assert(test.top() == 5); 
    }
   

    {
        stack<int> test;
        test.push(8);
        test.push(9);
        test.pop();
        assert(test.Empty() == false); 
    }  


    {
        //stack<String> test;
        //assert(test.full() == false); 
    }


    {
        //stack<char> test;
        //assert(test.empty() == true); 
    }     
    
    {
        //stack<char> test;
        //assert(test.full() == false); 
    }
    

    {
        //stack<String> test;
        //assert(test.full() == false); 
    }


    
    std::cout << "-->>TESTING COMPLETE FOR PUSH POP<<--" << std::endl;
    return 0;
}