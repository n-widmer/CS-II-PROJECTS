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
        int result = str.length();

        
        // VERIFY
        assert(result == 3);
        assert(str == "abc");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str = "a";
        int result = str.length();

        
        // VERIFY
        assert(result == 1);
        assert(str == "a");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str = "****************************************************************************************************************************************************************************************************************************************************************";
        int result = str.length();

        
        // VERIFY
        assert(result == 256);
        assert(str == "****************************************************************************************************************************************************************************************************************************************************************");
    }
    {
    //     //------------------------------------------------------
    //     // SETUP FIXTURE

    //     // TEST
        String str = "**********";
        int result = str.length();

        
        // VERIFY
        assert(result == 10);
        assert(str == "**********");
     }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing XXX." << std::endl;
    return 0;
}

