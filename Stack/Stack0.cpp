#include <iostream>
#include <string>
using namespace std;

template <typename E>
class Stack
{
    int top;
    E *ptr = NULL;
    int max_size;
    int size;
    int chunk_size;

public:
    void print()
    {
        cout << "< ";
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i] << ' ';
        }
        cout << '>' << endl;
    }
    Stack(int K)
    {
        top = 0;
        size = 0;
        chunk_size = sizeof(E);
        max_size = K;
        ptr = (E *)malloc(max_size * chunk_size);
    }
    Stack(int K, int X)
    {
        top = 0;
        size = 0;
        chunk_size = X;
        max_size = K;
        ptr = (E *)malloc(max_size * chunk_size);
       
    }

    void init()
    {
        ptr = (E *)realloc(ptr, max_size * chunk_size);
    }

    void push(E item)
    {

        if (size == max_size)
        {
            max_size *= 2;
            init();
        }
        *(ptr + top) = item;
        top++;
        size++;
    }
    E pop()
    {
        if (size > 0)
        {
            E temp = ptr[top - 1];
            top--;
            size--;
            return temp;
        }
        else
        {
            cout << "No elements left\n";
            return -1;
        }
    }
    void clear()
    {
        while (size > 0)
        {
            pop();
        }
    }
    int length()
    {
        return size;
    }
    E topValue()
    {
        if (top > 0)
            return ptr[top - 1];
        else
            return -1;
    }
    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }
};