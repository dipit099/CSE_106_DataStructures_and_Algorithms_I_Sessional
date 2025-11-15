#include <iostream>
#include "2105050_1_ll_queue.h"
using namespace std;
template <typename E>
class Queue
{

public:
    My_list<E> LL;

    LL_queue(){
    }
    void init()
    {
        LL.init();
    }
    void enqeue(E item)
    {
        LL.insert(item);
    }

    E dequeue()
    {
        E num = LL.remove();
        return num;
    }
    int length()
    {
        return LL.length();
    }
    E front()
    {
        LL.moveToStart();
        E temp = LL.getValue();
        return temp;
    }
    E back()
    {
        LL.moveToEnd();
        E temp = LL.getValue();
        return temp;
    }
    bool isEmpty()
    {
        if (LL.length() == 0)
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
        int num = LL.length();
        while (num != 0)
        {
            LL.moveToStart();
            LL.remove();
            num--;
        }
    }
    void print()
    {
        LL.print();
    }
};