
#include "utilities.hpp"
#include <fstream>
#include<iostream>

int main(int argc, char** argv){
    if (argc == 2){
        std::ifstream in(argv[1]);
        if(!in){std::cerr << "cannot open file" << argv[1]; exit(1);}
        char ch;
        String x;
        while(!in.eof()){
            ch = in.get();
            if(ch != '\n' && ch != '\r' && ch != ';'){
                x += ch;
            }
            else if(ch == '\n' && ch != '\r'){
                x += ';';
                std::cout << "Infix Expression is: " << x << std::endl;
                std::cout << toPostFix(x) << std::endl;
                toAssembly(std::cout, toPostFix(x));
                std::cout << std::endl;
                x = "";
            }
        }
        in.close();
    }
    else if(argc == 3){
        std::ifstream in(argv[1]);
        std::ofstream out(argv[2]);
        if(!in){std::cerr << "cannot open file"; exit(1);}
        if(!out){std::cerr << "cannot open file"; exit(1);}
            char ch;
            String x;
            while(!in.eof()){
                ch = in.get();
                if(ch != '\n' && ch != '\r' && ch != ';'){
                    x += ch;
                }
                else if(ch == '\n' && ch != '\r'){
                    x += ';';
                    std::cout << "Infix Expression is: " << x << std::endl;
                    std::cout << toPostFix(x) << std::endl;
                    toAssembly(std::cout, toPostFix(x));
                    std::cout << std::endl;
                    x = "";
                }

            }
           // toAssembly(out, x);
            in.close();
            out.close();
    }else{
        std::cout << "Usage." << argv[0] << "input file [output file]" << std::endl;
    }
}
