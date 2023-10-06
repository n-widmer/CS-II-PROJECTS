//  Stack class test program
//
//  Tests: DTOR Test
//

#include "stack.hpp"
#include <iostream>
#include "../string/string.hpp"

int main() 
{
    {
    stack<int> a;
    a.push(44);

    a.~stack();

    assert(a.Empty() == true);
    }

    {
        stack<int> a;
        a.push(33);
        a.push(90);
        a.push(449940);
        a.push(3388383);
        a.push(77338);

        a.~stack();

        assert(a.Empty() == true);
    }

    {
        stack<char> a;
        a.push('a');
        a.push('b');
        a.push('c');

        a.~stack();

        assert(a.Empty() == true);

    }

    {
        stack<char> a;
        a.push('q');
        a.push('a');
        a.push('b');
        a.push('c');
        a.push('r');

        a.~stack();

        assert(a.Empty() == true);
    }

    {
        stack<String> a;
        a.push("my name is nick");
        a.push("i am in discrete math");
        a.push("it is hard");

        a.~stack();

        assert(a.Empty() == true);
    }

    {
        stack<String> a;
        a.push("abcde");
        a.push("vhrjvk");
        a.push("kewmklrvnm");
        a.push("vjernvjirenv");
        a.push("cejkcnejkncvd");
        a.push("z");

        a.~stack();

        assert(a.Empty() == true);
    }

    std::cout << "Done testing DTOR" << std::endl;

}