// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times_digit(0);

        // Verify
        assert(bi == 0);  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(2);

        // Test 
        bi = bi.times_digit(2);

        // Verify
        assert(bi == 4);  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

        // Test 
        bi = bi.times_digit(0);

        // Verify
        assert(bi == 0);  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi = bi.times_digit(1);

        // Verify
        assert(bi == 1);  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

        // Test 
        bi = bi.times_digit(1);

        // Verify
        assert(bi == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");  //Will FAIL, fix and add test cases.
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("123456789");

        // Test 
        bi = bi.times_digit(1);

        // Verify
        assert(bi == "123456789");  //Will FAIL, fix and add test cases.
    }


    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}
