#include <bits/stdc++.h>
#include "2105050_2_stack.cpp"
using namespace std;

template <typename E>
void func()
{
    Stack<E> mystack;
    mystack.print();

    int Q;
    cin >> Q;
    while (Q != 0)
    {
        if (Q == 1)
        {
            cout << "Push" << endl;
            E item;
            cin >> item;
            mystack.push(item);
            mystack.print();
        }
        else if (Q == 2)
        {
            cout << "Pop:" << endl;
            E n = mystack.pop();
            mystack.print();
            if (mystack.length() == 0)
                cout << "-1" << endl;
            else
            cout << n << endl;
        }
        else if (Q == 3)
        {
            cout << "Length" << endl;
            int l = mystack.length();
            mystack.print();
            cout << l << endl;
        }
        else if (Q == 4)
        {
            cout << "The topvalue is" << endl;
            mystack.print();
            if (mystack.length() == 0)
                cout << "-1" << endl;
            else
            {
                E n = mystack.topValue();
                cout << n << endl;
            }
        }
        else if (Q == 5)
        {
            if (mystack.isEmpty())
                cout << "Empty Stack\n";
            else
                cout << "Stack is not empty\n";
            mystack.print();
        }
        else if (Q == 6)
        {
            mystack.clear();
            mystack.print();
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
