// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        //assert(bi    == 800);  //Wrong.  Will FAIL.  Fix and add test cases.
        //assert(digit == 0);
        assert(bi == 4);
        assert(digit == 4);
    }
    {
        // Setup
        bigint bi(2345);


        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 2345);  
        assert(digit == 4);

    }
    {
        // Setup
        bigint bi("1000000000000000000001000000054");


        // Test 
        int digit = bi[9];

        // Verify
        assert(bi    == "1000000000000000000001000000054");  
        assert(digit == 1);

    }
    {
        // Setup
        bigint bi(10);


        // Test 
        int digit = bi[3];

        // Verify
        assert(bi    == 10);  
        assert(digit == 0);

    }
    
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

