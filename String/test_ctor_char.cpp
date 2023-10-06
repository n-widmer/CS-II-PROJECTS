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
        String  str1 = 'w';
        // String  str2 = "";


        // VERIFY
        assert(str1[0] == 'w');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1 = ' ';
        // String  str2 = "";


        // VERIFY
        assert(str1[0] == ' ');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1 = 'P';
        // String  str2 = "";


        // VERIFY
        assert(str1[0] == 'P');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1 = 'o';
        // String  str2 = "";


        // VERIFY
        assert(str1[0] == 'o');
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing CHAR_CONSTRUCTOR." << std::endl;
    return 0;
}

