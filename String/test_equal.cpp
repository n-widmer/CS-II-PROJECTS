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
        String  str1("he");

        String  str2("he");


        // VERIFY
        //std::cout << str1 << std::endl;
        assert(str1 == str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("aaaaaAAAAA");
        String  str2("aaaaaAAAAA");


        // VERIFY
        assert(str1 == str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("ThisIsToSeeIfTheStringsAreEqual");
        String  str2("ThisIsToSeeIfTheStringsAreEqual");


        // VERIFY
        assert(str1 == str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("I REALLY HOPE THIS WORKS");
        String  str2("I REALLY HOPE THIS WORKS");
        //std::cout << str1 << std::endl;


        // VERIFY
        assert(str1 == str2);
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing EQUAL." << std::endl;
    return 0;
}

