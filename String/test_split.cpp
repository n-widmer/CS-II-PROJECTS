#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main ()
{
 {
    // SETUP
    std::vector<String> test = String("Hello World").split(' ');
    //std::cout << test[0] << std::endl;
    //std::cout << test[1] << std::endl;
    
    // VERIFY
    assert(test[0] == "Hello");
    assert(test[1] == "World");
}
 {
    // SETUP
    std::vector<String> test = String("abc de fg").split(' ');
    //std::cout << test[0] << std::endl;
    //std::cout << test[1] << std::endl;
    
    // VERIFY
    assert(test[0] == "abc");
    assert(test[1] == "de");
    assert(test[2] == "fg");
}
 {
    // SETUP
    std::vector<String> test = String("a-b-d-e-f").split('-');
    //std::cout << test[0] << std::endl;
    //std::cout << test[1] << std::endl;
    
    // VERIFY
    assert(test[0] == "a");
    assert(test[1] == "b");
    assert(test[2] == "d");

}
 {
    // SETUP
    std::vector<String> test = String("a-b-d-e-f").split('-');
    //std::cout << test[0] << std::endl;
    //std::cout << test[1] << std::endl;
    
    // VERIFY
    assert(test[0] == "a");
    assert(test[1] == "b");
    assert(test[2] == "d");
    assert(test[3] == "e");
    assert(test[4] == "f");
}
 {
    // SETUP
    std::vector<String> test = String("--a").split('-');
    std::cout << test[0] << std::endl;
    //std::cout << test[1] << std::endl;
    
    // VERIFY
    assert(test[0] == "");

}
 std::cout << "Done testing for SPLIT." << std::endl;
}