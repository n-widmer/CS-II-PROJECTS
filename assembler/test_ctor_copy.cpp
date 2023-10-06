#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"


int main()
{
    {
        stack<int> a;
        a.push(6);

        stack<int> copyA(a);

        assert(copyA.top() == a.top());
    }

    {
        stack<String> a;
        a.push("this is cool");

        stack<String> copyA(a);

        assert(copyA.top() == a.top());
    }

    {
        stack<String> a;
        a.push("hello");

        stack<String> copyA(a);

        assert(copyA.top() == a.top());
    }

    {
        stack<char> a;
        a.push('8');
        a.push('9');
        a.push('5');
        a.pop();

        stack<char> copyA(a);

        assert(copyA.top() == a.top());
    }

    {
        stack<int> a;
        a.push(6);
        a.push(5);
        a.push(2);

        stack<int> copyA(a);

        assert(copyA.top() == a.top());
    }

    {
        stack<String> a;
        a.push("hello");
        a.push("world");
        a.push("are you there?");

        stack<String> copyA(a);

        assert(copyA.top() == a.top());
    }

    {
        stack<char> a;
        a.push('a');
        a.push('b');
        a.push('c');
        a.push('d');
        a.push('e');

        stack<char> copyA(a);

        assert(a.Empty() == false);
        assert(copyA.Empty() == false);
        assert(copyA.top() == a.top());
    }

    std::cout<< "Done testing COPY CTOR" << std::endl;

}