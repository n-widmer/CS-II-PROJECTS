#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include <iostream>
#include <fstream>
#include "stack.hpp"
#include "../string/string.hpp"

String toPostFix(String);
void toAssembly(std::ostream&, const String&);
String evaluate(std::ostream&, const String&, const String&, const String&, int&);
String toString(const int&);

#endif // UTILITIES_HPP
