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
        String str = "abc";
        String str2 = "abc";
        bool result = (str < str2);

        
        // VERIFY
        assert(result == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
       String str("abcd");
       std::cout << str;
       String str2("abcde");
       bool result = (str < str2);


        
        // VERIFY
        assert(result == true);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
       String str("A");
       String str2("B");
       bool result = (str < str2);
        
        // VERIFY
        assert(result == true);
    }
    {
    //     //------------------------------------------------------
    //     // SETUP FIXTURE

    //     // TEST
       String str("a");
       String str2("bcaa");
       bool result = (str < str2);
        
        // VERIFY
        assert(result == true);
     }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing LESS_THAN." << std::endl;
    return 0;
}

