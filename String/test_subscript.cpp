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
        String strOne("Hello");
        char ch = strOne[0];
        std::cout << strOne << std::endl;


        // VERIFY
        assert(strOne == "Hello");
        assert(ch == 'H');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1 = "Kent State";



        // VERIFY
        assert(str1[4] == ' ');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1 = "I have been doing this for so long:(";
        // String  str2 = "";


        // VERIFY
        assert(str1[35] == '(');
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
    
    std::cout << "Done testing SUBSCRIPT." << std::endl;
    return 0;
}

