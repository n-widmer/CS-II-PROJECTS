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
        String  str1("qwerty");
        String  str2("asdf");
        str1 += str2;


        // VERIFY
        assert(str1 == "qwertyasdf");
        assert(str2 == "asdf");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("QwErTyUiOp");
        String  str2("zXcVbNm");
        str1 += str2;


        // VERIFY
        assert(str1 == "QwErTyUiOpzXcVbNm");
        assert(str2 == "zXcVbNm");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("abc");
        String  str2("123");
        str1 += str2;


        // VERIFY
        assert(str1 == "abc123");
        assert(str2 == "123");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("Hello, my name is: ");
        String  str2("Nicholas");
        str1 += str2;


        // VERIFY
        assert(str1 == "Hello, my name is: Nicholas");
        assert(str2 == "Nicholas");
    }
     {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("");
        String  str2("");
        str1 += str2;


        // VERIFY
        assert(str1 == "");
        assert(str2 == "");
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing CONCAT." << std::endl;
    return 0;
}

