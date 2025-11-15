#include <bits/stdc++.h>
#include "2105050_1_a_queue.h"
using namespace std;
template <typename E>
class Queue
{

public:
    My_list<E> arr;

    Arr_queue()
    {
    }
    void init()
    {
        arr.init();
    }
    void enqeue(E item)
    {
        arr.insert(item);
    }

    E dequeue()
    {
        E num = arr.remove();
        return num;
    }
    int length()
    {
        return arr.length();
    }
    E front()
    {
        arr.moveToPos(arr.front);       
        E temp = arr.getValue();
        return temp;
    }
    E back()
    {
        arr.moveToPos(arr.tail);
        E temp = arr.getValue();
        return temp;
    }
    bool isEmpty()
    {
        if (arr.length() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void clear()
    {
        arr.size = 0;
        arr.front = 1;
        arr.tail = 0;
    }
    void print()
    {
        arr.print();
    }
};