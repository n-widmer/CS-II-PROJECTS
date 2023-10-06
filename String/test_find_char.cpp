 //  String class test program
//
//  Tests: XXX 
//
 
#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        // char ch;
        String  s1 = "abcdefghijklmnopqrstuvwxyz";
        int pos = s1.findch(0, 'f');
        
        // VERIFY
        assert(pos == 5);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        //char ch;
        String  s1 = "computerscience";
        int pos = s1.findch(0, 'c');
        
        // VERIFY
        assert(pos == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        //char ch;
        String  s1 = "hello world";
        int pos = s1.findch(10, 'd');
        
        // VERIFY
        assert(pos == 10);
    }
    {
    //     //------------------------------------------------------
    //     // SETUP FIXTURE

    //     // TEST
        //char ch;
        String  s1 = "hi my name is";
        int pos = s1.findch(3, ' ');
        
        // VERIFY
        assert(pos == 5);
     }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing FIND_CHAR." << std::endl;
    return 0;
}

