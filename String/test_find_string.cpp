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
        String  s1 = "abcdefghijklmnopqrstuvwxyz";
        String  s2 = "stuv";
        int pos = s1.findstr(3, s2);
        
        // VERIFY
        assert(pos == 18);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1 = "computer science";
        String  s2 = "computer";
        int pos = s1.findstr(0, s2);
        
        // VERIFY
        assert(pos == 0);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1 = "nick widmer";
        String  s2 = "k w";
        int pos = s1.findstr(3, s2);
        
        // VERIFY
        assert(pos == 3);
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
    
    std::cout << "Done testing FIND_STRING." << std::endl;
    return 0;
}

