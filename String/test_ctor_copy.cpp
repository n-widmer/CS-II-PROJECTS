#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main (){
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("hello");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "hello");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("This is going to be a very long string. I am just going to keep typing random words on this line until i cannot think of anything else possibly to write down. While I am doing this i am sitting at the library on the 9th floor studying for my discrete structures exam tomorrow.");       // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "This is going to be a very long string. I am just going to keep typing random words on this line until i cannot think of anything else possibly to write down. While I am doing this i am sitting at the library on the 9th floor studying for my discrete structures exam tomorrow.");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("!@(U$(&$*!&$**$&*(!&$()!*@#)(!*()#*!&$*(!)@$&*)(!*$()!)($)_!*$(&!*$!**$O!&$()!(*!(@)$*!)($*(!@$(*!@)($*()!*%*(&%!(@*)$(!*(");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "!@(U$(&$*!&$**$&*(!&$()!*@#)(!*()#*!&$*(!)@$&*)(!*$()!)($)_!*$(&!*$!**$O!&$()!(*!(@)$*!)($*(!@$(*!@)($*()!*%*(&%!(@*)$(!*(");   
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("                                           space                                      ");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "                                           space                                      ");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("hello");
        // TEST
        String b(a);
        a = b;
        b = a;
        b += a;
        // VERIFY
        assert(b == "hellohello");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("1230 + 1230 = 2460");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "1230 + 1230 = 2460");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("C++C++C++C++C++C++C++C++C++C++C++C++C++C++C++");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "C++C++C++C++C++C++C++C++C++C++C++C++C++C++C++");    
    }

    std::cout << "Done testing for COPY CONSTRUCTOR" << std::endl;
    return 0;
}