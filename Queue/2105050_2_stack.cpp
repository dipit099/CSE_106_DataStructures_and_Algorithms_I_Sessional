#include <bits/stdc++.h>
#include "2105050_1_a_queue.cpp"
 //#include"2105050_1_ll_queue.cpp"
using namespace std;
template <typename E>
class Stack 
{
    Queue<E> present;
    Queue<E> temp;

public:
    
    Stack()
    {
        present.init();
        temp.init();
    }
    void push(E item)
    {
        present.enqeue(item);
    }
    E pop()
    {
        int p_length = present.length();
        for (int i = 0; i < p_length - 1; i++)
        {
            temp.enqeue(present.dequeue());
        }

        E store = present.dequeue();
        int t_length = temp.length();
        for (int i = 0; i < t_length; i++)
        {
            present.enqeue(temp.dequeue());
        }
        return store;
    }
    int length()
    {
        return present.length();
    }
    E topValue()
    {
        return present.back();
    }
    bool isEmpty()
    {
        return present.isEmpty();
    }
    void clear()
    {
        present.clear();
    }
    void print()
    {
        present.print();
    }
};
