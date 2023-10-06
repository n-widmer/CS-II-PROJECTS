//
//  STACK ADT.hpp
//  CODE
//
//  Created by Nicholas Widmer on 2/27/23.
//

#ifndef STACK_ADT_hpp
#define STACK_ADT_hpp

#include <stdio.h>
#include <cassert>

const int SIZE = 100;
template <typename T>
class stack{
public:
    stack() : tos(-1) {};
    bool isEmpty() const {return tos == -1; };
    bool isFull() const {return tos == SIZE -1; }; // if we are at size- 1 we are full
    void push(const T&);
    T    pop();
    T    top() const{ return s[tos]; };
    
    
    
private:
    int tos;
    T   s[SIZE];
};

template <typename T>
void stack<T>::push(const T& item){
    assert(!isFull()); // check to make sure stack is not full
    s[++tos] = item; // incrementing position of tos first on purpose to populate the new index
}

template<typename T>
T stack<T>::pop(){
    assert(!isEmpty()); // check for stack underflow
    return s[tos--]; // post-decrement cause you want to pop the index before hand and then decrement again
    
}

#endif
