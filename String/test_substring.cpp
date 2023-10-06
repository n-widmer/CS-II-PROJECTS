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
        String  str1 = "Hello My Name is Nick Widmer";
        String sub = str1.substr(0, 5);
        std::cout << sub << std::endl;



        // VERIFY
        assert(sub == "Hello ");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str1 = "Computer.Science";
        String sub = str1.substr(8, 10);
        std::cout << sub << std::endl;


        // VERIFY
        assert(sub == ".Sc");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1 = "abcdefghijklmnopqrstuvwxyz";
        String sub = str1.substr(5, 12);

        // VERIFY
        assert(sub == "fghijklm");
    }
    // {
    //     //------------------------------------------------------
    //     // SETUP FIXTURE

    //     // TEST
    //     String  str1 = 'o';
    //     // String  str2 = "";


    //     // VERIFY
    //     assert(str1[0] == 'o');
    // }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing SUBSTRING." << std::endl;
    return 0;
}

