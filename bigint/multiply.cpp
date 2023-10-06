// File: main.cpp
//
// CS 23001 Project 1 bigint
//
// Basics for openning a file for milestone 2
//

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-2.txt");      // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }
    
    while(!(in.eof())){
        bigint one, two, result;
        in >> one >> two;
        //one.debugPrint(std::cout);
        std::cout << "bigint one: " << one << std::endl;
        std::cout << "bigint two: " << two << std::endl;
        result = one * two;
        std::cout << "result: " << result << std::endl;
    }
    in.close();
    return 0;
}