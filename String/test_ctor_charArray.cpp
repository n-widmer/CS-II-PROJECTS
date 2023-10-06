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
        String  str1("qwertyuiop");
        // String  str2 = "";


        // VERIFY
        assert(str1 == "qwertyuiop");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("AsDfGhJkL");
        // String  str2 = "";


        // VERIFY
        assert(str1 == "AsDfGhJkL");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1 = "aa";
        // String  str2 = "";


        // VERIFY
        assert(str1 == "aa");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1 = 'o';
        // String  str2 = "";


        // VERIFY
        assert(str1 == 'o');
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing CHAR_ARRAY." << std::endl;
    return 0;
}

