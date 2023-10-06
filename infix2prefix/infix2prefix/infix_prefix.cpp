
#include "stack.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include "../string/string.hpp"
String infix_to_prefix(String result){
    stack<String> S;
    String rhs, lhs, op;
    std::vector<String> token = result.split(' ');
    int i = 0;
//----------------------------------------------//
//==============================================//
    while(token[i] != ';'){
        if (token == ')'){
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            S.push(op + lhs + rhs);
        } else if (token[i] != '('){
            String temp = " ";
            temp[0] = result[i];
            S.push(temp);
        }
        ++i;   
    }
    return S.pop();
}
void readLine(){
     std::ifstream file ("data3-1.txt");
    if(file.fail()) {
        std::cout << "Unable to open file\n";
    }
    char ch;
    file.get(ch);
    while(ch != ' ') {
        result += ch;
        file.get(ch);
    }
    std::cout << '\n';
    std::cout << result << std::endl;
    file.close();
}


