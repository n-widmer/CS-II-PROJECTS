#include "utilities.hpp"

String toPostFix(String infix){
 stack<String> s;
 String postFix, right, left, op;
 std::vector<String> token = infix.split(' ');
 int i = 0;
 while(token[i] != ';'){
     if(token[i] == ")"){
         right = s.pop();
         op    = s.pop();
         left  = s.pop();
         s.push(left + " " + right + " " + op);
     } 
     else if(token[i] != "("){
         s.push(token[i]);
     }
    ++i;
 }
 return s.pop() + " ;";
}

void toAssembly(std::ostream& out, const String& Str){
    std::vector<String> token = Str.split(' '); //splitting the spaces out of the expression
    stack<String> s;
    String lhs, rhs;
    int i = 0;
    int n = 0; //used for keeoing strack of the registries
    while(token[i] != ';'){
        if(token[i] != '*' && token[i] != '+' && token[i] != '-'){ //adding everything to the stack that is not an operator
            s.push(token[i]); //adding the first characters to the stack
        }else{
            rhs = s.pop(); //since we pushed things we have to pop
            lhs = s.pop();

            s.push(evaluate(out, lhs, rhs, token[i], n)); //out = output stream,, lhs = AX,, rhs = B,, token[i] = operator,, n = register

        }
        ++i;
    }


}
String evaluate(std::ostream& out, const String& lhs, const String& rhs, const String& Str, int& n){
    out << "LD" << " " << lhs << std::endl;
    if(Str == '+'){
        out << "AD" << " " << rhs << std::endl;
        ++n;

    }
    else if(Str == '-'){
        out << "SB" << " " << rhs << std::endl;
        ++n;
    }
    else if(Str == '*'){
        out << "MU" << " " << rhs << std::endl;
        ++n;

    }
    else if(Str == '/'){
        out << "DV" << " " << rhs << std::endl;
        ++n;
    }
    out << "ST" << " " << "TMP" << n << std::endl;
    return "TMP" + toString(n);

}

String toString(const int& x){
    String result = '0' + x;
    return result;
}