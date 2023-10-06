#include <fstream>
#include <cassert>
#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"

String toPostFix(String infix){
    String postFix;

    stack<String> s;
    String right, left, op;
    std::vector<String> token = infix.split(' ');

    int i = 0;
    while(token[i] != ";"){

        if(token[i] == ")"){
            right = s.pop();
            op    = s.pop();
            left  = s.pop();
            s.push(left + " " + right + " " + op);
        } else {
            if(token[i] != "("){
                s.push(token[i]);
            }

        }
        ++i;
    }
    postFix = s.top(); // sets beginning of string to postfix
    s = stack<String>(); // once its done, we reset the stack

    return postFix;
}

int main() {
    {
        String s = "( ( A + B ) * ( K + L ) ) ;";
        String postFix;
        postFix = toPostFix(s);
        assert(postFix == "A B + K L + *");
    }

    {
        String a = "( ( AX * BX ) + ( ( ( ( ( ( CX - DY ) * EX ) * FX ) * GY ) * HX ) + JY ) ) ;";
        
    }
    
    std::cout << "Done testing ToPostFix" << std::endl;
}