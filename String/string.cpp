// Nick Widmer
// 02/22/2023
// class implemetation


#include "string.hpp"

String::String(){
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
}

// copy constructor
// makes an exact copy of the object that is sent to another object
String::String(const String& actual){
    stringSize = actual.stringSize;
    str = new char[stringSize];
    for(int i = 0; i < stringSize; ++i){
        str[i] = actual.str[i];
    }

}
// deallocates the new array in memory once the program ends
String::~String(){
    delete[] str;
}

String::String(char x){
    if (x == '\0'){
        stringSize = 1;
        str = new char[stringSize];
        str[0] = '\0';
    } else {
        stringSize = 2;
        str = new char[stringSize];
        str[0] = x;
        str[1] = '\0';
    }

}

String::String(const char s[]){
    stringSize = 0;
    while (s[stringSize] != '\0'){
        ++stringSize;
    }

    ++stringSize;

    str = new char[stringSize];

    for (int i = 0; i < stringSize; ++i){
        str[i] = s[i];
    }
    str[stringSize -1] = '\0';

}

void String::swap(String& rhs){
    char* tmp = str;
    str = rhs.str;
    rhs.str = tmp;

    int capTemp = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = capTemp;

}

int String::capacity() const{
   return stringSize -1;
}

int String::length() const{
    /*
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len; 
    */

    return capacity();
}

char& String::operator[](int i){
    // // assert(0 <= i);
    // if (length() == 0)
    //     return str[0];
    // assert(i <= length());s
    // return str[i];
    assert(i >= 0);
    assert(i <= length());
    return str[i];

}

char String::operator[](int i) const{

    // // assert(0 <= i);
    // if (length() == 0)
    //     return str[0];
    // assert(i <= length());
    // return str[i];
    assert(i >= 0);
    assert(i <= length());
    return str[i];

   
}

String& String::operator+=(const String& rhs){
    if(rhs.length() == 0){
        return *this;
    }

    if(length() == 0){
        *this = rhs;
        return *this;
    }

    int newLen = stringSize + rhs.stringSize - 1;
    char* newStr = new char[newLen];
    for (int i = 0; i < this->length(); ++i){
        newStr[i] = str[i];
    }

    for(int i = 0; i < rhs.stringSize; ++i){
        newStr[this->length() + i] = rhs.str[i];
    }
    stringSize = newLen;
    delete [] str;
    str = newStr;
    return *this;
}

String& String::operator=(String rhs){
    swap(rhs);
    return *this;

}

String String::substr(int start, int end) const{
    if(start < 0) {start = 0;}
    if(end < start){return String();}
    if(end >= length()){end = length() - 1;}
    String result;
    delete[] result.str;
    result.str = new char [end - start + 2];
    int x = 0;
    for(int i = start; i <= end; ++i){
        result.str[x] = str[i];
        ++x;
    }
    result.stringSize = x + 1;
    result[x] = '\0';
    return result;
}


int String::findch(int start, char ch) const{
    if (start < 0 || start >= length())
        return -1;
    int i = start;
    while(str[i] != '\0'){
        if (str[i] == ch){
            return i;
        }
        ++i;
    }
    return -1;
}

int String::findstr(int pos, const String& eq) const {
    assert(pos >= 0);
    for(int i = pos; i <= length() - eq.length(); ++i)
    if(substr(i, i + eq.length() -1) == eq){
        return i;
    }
    return -1;
}

std::istream& operator>>(std::istream& in, String& rhs){
    char arr[512];
    in >> arr;
    rhs = String(arr);

    return in;

}

std::ostream& operator<<(std::ostream& out, const String& rhs){
    for(int i = 0; i < rhs.length(); ++i){
        out << rhs.str[i];
    }
    return out;

}
bool String::operator==(const String& rhs)  const{
    int j = 0;
    while((str[j] != 0) && (rhs.str[j] != 0) && (str[j] == rhs.str[j])){
        ++j;
    }
    return str[j] == rhs.str[j];
}

std::vector<String>String::split(char ch) const{
    std::vector <String> result;
    int currPos = 0;
    while(findch(currPos, ch) != -1){
        result.push_back(substr(currPos, findch(currPos, ch)-1));
        currPos = (findch(currPos, ch)) + 1;
    }
    result.push_back(substr(currPos, this->length()-1));

    return result;
}

bool operator==(const char cA[],  const String& rhs){ // not a member function, no need to use '::' operator
return String(cA) == rhs;
}

bool operator==(char ch, const String& rhs){ // not a member function, no need to use '::' operator
return String(ch) == rhs;
}

bool String::operator<(const String& rhs) const{
    int i = 0;
    while((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])){
        ++i;
    }
    return str[i] < rhs.str[i];
}

bool operator<(char lhs, const String& rhs){
    return String(lhs) < rhs;

}

bool operator<(const char lhs[], const String& rhs){
    return String(lhs) < rhs;
}

bool operator!=(const String& lhs, const String& rhs){
    return !(lhs == rhs);
}

bool operator>(char lhs, const String& rhs){
    return rhs < lhs;

}
bool operator>(const String& lhs, const String& rhs){
    return rhs < lhs;

}

// bool operator<=(char lhs, const String& rhs){
//     return !(lhs > rhs);

// }
bool operator<=(const String& lhs, const String& rhs){
    return !(lhs > rhs);

}

bool operator>=(char lhs, const String& rhs){
    return !(rhs < lhs);
}

String operator+(String lhs, const String& rhs){ //calling a copy instructor for lhs in essence
    return lhs += rhs;
}

