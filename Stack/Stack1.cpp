#include <iostream>
#include <string>
#include"Stack0.cpp"
using namespace std;

template <typename E>
void func()
{
    int K, X;
    cin >> K >> X;
    Stack<E> mystack(K, X);
    
    for (int i = 0; i < K; i++)
    {
        E temp;
        cin >> temp;
        mystack.push(temp);
    }
    mystack.print();
    int Q;
    cin >> Q;
    while (Q != 0)
    {
        if (Q == 1)
        {
            mystack.clear();
            mystack.print();
        }
        else if (Q == 2)
        {
            E item;
            cin >> item;
            mystack.push(item);
            mystack.print();
        }
        else if (Q == 3)
        {
            E n = mystack.pop();
            mystack.print();
            cout << n << endl;
        }
        else if (Q == 4)
        {
            int l = mystack.length();
            mystack.print();
            cout << l << endl;
        }
        else if (Q == 5)
        {
            E n = mystack.topValue();
            mystack.print();
            cout << n << endl;
        }
        else if (Q == 6)
        {
            if (mystack.isEmpty())
                cout << "Empty Stack\n";
            else
                cout << "Stack is not empty\n";
            mystack.print();
        }
        cin >> Q;
    }
}
void file()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int main()
{
    // file();
    cout << "What type of stack?\n";
    string s;
    cin >> s;    

    if (s == "char")
    {      
        func<char>();        
    }
    else if (s == "int")
    {        
        func<int>();        
    }
    else if(s ==  "double")
    {
        func<double>();
    }
}
