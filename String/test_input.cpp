 //  String class test program
//
//  Tests: XXX 
//
 
#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

 
//===========================================================================
int main ()
{


     std::ifstream file ("data1.txt");
    if(file.fail()) {
        std::cout << "Unable to open file\n";
    }

    String x;

    std::cout << "Input: This is a test." << std::endl;
    while(!(file.eof())) {
        file >> x;
        std::cout << "result: " << x<< std::endl;
    }
    std::cout << "Done testing INPUT" << std::endl;
    file.close();
}
