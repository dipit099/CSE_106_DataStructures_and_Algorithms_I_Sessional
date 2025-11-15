#include <bits/stdc++.h>
//#include "2105050_1_a_queue.cpp"
#include"2105050_1_ll_queue.cpp"
using namespace std;
template <typename E>
void func()
{
    Queue<E> myqueue;
    myqueue.print();

    int Q;
    cin >> Q;
    while (Q != 0)
    {

        if (Q == 1)
        {
            cout << "Enqueue:" << endl;
            E item;
            cin >> item;
            myqueue.enqeue(item);
            myqueue.print();
        }
        else if (Q == 2)
        {
            cout << "Dequeue:" << endl;
            E n;
            int temp = 0;
            if (myqueue.length() == 0)
                temp = -1;
            else
                n = myqueue.dequeue();

            myqueue.print();
            if (temp == -1)
                cout << temp << endl;
            else
                cout << n << endl;
        }
        else if (Q == 3)
        {
            cout << "Length" << endl;
            int l = myqueue.length();
            myqueue.print();
            cout << l << endl;
        }
        else if (Q == 4)
        {
            cout << "The Front Value is" << endl;

            myqueue.print();
            if (myqueue.length() == 0)
                cout << "-1" << endl;
            else
            {
                E n = myqueue.front();
                cout << n << endl;
            }
        }
        else if (Q == 5)
        {
            cout << "The Back Value is" << endl;
            myqueue.print();
            if (myqueue.length() == 0)
                cout << "-1" << endl;
            else
            {
                E n = myqueue.back();
                cout << n << endl;
            }
        }
        else if (Q == 6)
        {
            if (myqueue.isEmpty())
                cout << "Empty Stack\n";
            else
                cout << "Stack is not empty\n";
            myqueue.print();
        }
        else if (Q == 7)
        {
            cout << "Clear" << endl;
            myqueue.clear();
            myqueue.print();
        }
        cin >> Q;
    }
    return;
}
int main()
{
    cout << "What type of data do you want to store in the queue?" << endl;
    cout << "1. Int" << endl;
    cout << "2. Char" << endl;
    int p;
    cin >> p;
    if (p == 1)
    {
        func<int>();
    }
    else if (p == 2)
    {
        func<char>();
    }
}
