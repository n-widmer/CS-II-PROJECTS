//Nick Widmer
//1-26-2023
//big int  cpp file





#include <iostream>
#include "bigint.hpp"

bigint::bigint(){
    //default constructor initializing bigint to 0.
 for(int i = 0; i < capacity; ++i){
    bi[i] = 0;
 }

}

bigint::bigint(int x) : bigint(){
    /*second constructor initializing bigint to
    whatever is passed as an argument*/ 
    for(int i = 0 ; i < capacity; ++i){
        bi[i] = x % 10; // populating index i with the end digit of x
        x /= 10; // slicing off that last digit of x
    } 


}

bigint::bigint(const char numChar[]) : bigint() {
    int len = 0; // declaring a len variable to gert
    while( numChar[len] != '\0'){
        ++len;
    }

    int k = 0;
    for(int i = len -1; i >= 0; --i){
        bi[k] = numChar[i] - '0';
        ++k;
    }
}

void bigint::debugPrint(std::ostream& out) const {
for(int i = capacity - 1; i >= 0; --i){
   out << bi[i] << " | ";
}

}
std::ostream& operator<<(std::ostream& out, bigint rhs){
int j = 0;
int length = capacity -1;
while(rhs.bi[length] == 0){
    --length;
}

if (length < 0){
    out << 0;
}

for(int i = length; i >= 0; --i){
    if(j == 80){
        out << std::endl;
        j = 0;
    }
    out << rhs.bi[i];
    ++j;
}
return out;
}

bool bigint::operator==(const bigint rhs){
    for(int i = 0; i < capacity; ++i){
        if(bi[i] != rhs.bi[i]){
            return false;
        }
    }
    return true;
}


std::istream& operator>> (std::istream& in, bigint& rhs){
    char charArray[capacity] = {0};
    char c = 0;
    int length = 0;
    // in >> c;
    // while(c != ';'){
    //     if(in.eof()){break;}
    //     charArray[length] = c;
    //     ++length;
    //     in >> c;
    // }
    while(in >> c) {
        if(c == ';')
            break;
        charArray[length++] = c;
    }
    charArray[length] = '\0';
    int track = 0;
    for(int i = length - 1; i >= 0; --i){
        rhs.bi[track] = charArray[i] - '0';
        ++track;
    }

    return in;
}

bigint bigint::operator+(const bigint& rhs) const{
    int carry = 0;
    bigint sum;

    for(int i = 0; i < capacity; ++i){
        int temp = bi[i] + rhs.bi[i] + carry;
        sum.bi[i] = temp %10;
        carry = temp / 10;
   }
   return sum;

}

int bigint::operator[](int x) const{
    if(x < 0 || x > capacity - 1){
        return 0;

    }
    else{
        return bi[x];
    }


}

bigint bigint::times_digit(int x) const{
    bigint result;
    int carry = 0;
    int temp = 0;
    for(int i = 0; i < capacity; ++i){
        temp = (bi[i] * x) + temp; // multiplying index of i by num and adding the carried over digit
        carry = temp % 10; // sending the cut off digit 
        temp /= 10; // storing the non cut off digits in a temp var
        result.bi[i] = carry % 10;
    }
    return result;
}

bigint bigint::times10(int num)const{
    bigint result;
    for(int i = capacity - 1 - num; i >= 0; --i){ // shift left until the index of num is reached
        result.bi[num + i] = bi[i];
    }
    return result;
}

bigint bigint::operator*(bigint rhs){
    bigint temp;
    bigint product;

    for(int i = 0; i < capacity - 1; ++i){
        temp = times_digit(rhs.bi[i]);
        product = product + temp.times10(i);
    }
    return product;
}

// int main() {
//     bigint b1;
//     int b2;
//     std::cin >> b1;
//     std::cin >> b2;
//     std::cout << b1 * b2 << std::endl; 
// }




    



