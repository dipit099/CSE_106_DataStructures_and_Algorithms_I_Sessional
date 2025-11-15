#include<bits/stdc++.h>
using namespace std;
//#include "2105050_1_a_queue.cpp"
#include"2105050_1_ll_queue.cpp"
template <typename E>
void func()
{
    Queue<E> myqueueA;
    Queue<E> myqueueB;
    Queue<E> myqueueC;
    string s;
    getline(cin,s);
   
    while(s !=  "terminate")
    {
        if(s[0]>='0' && s[0]<='9')
        {
            int num = s[0]-'0';
            if(myqueueB.length()<myqueueC.length())
            {
                myqueueB.enqeue(num);
                cout << "Customer " << num <<" enter queue B\n";
            }
            else if(myqueueB.length()>myqueueC.length())
            {
                myqueueC.enqeue(num);
                cout << "Customer " << num <<" enter queue C\n";
            }
            else
            {
                myqueueB.enqeue(num);
                cout << "Customer " << num <<" enter queue B\n";
            }

        }
        else if(s[2]== 'a')
        {
            if(s[0] == 'A')
            {
                if(myqueueA.length()==0)
                    cout << "Queue A was already empty\n";
                else
                {
                     int num = myqueueA.dequeue();
                     
                cout << "Customer " << num <<" gets the loan\n";
                }

            }
            else if(s[0] == 'B')
            {
               
                if(myqueueB.length()==0)
                    cout << "Queue B was already empty\n";
                else
                {
                     int num = myqueueB.dequeue();
                     myqueueA.enqeue(num);
                cout << "Customer " << num <<" enter queue A\n";
                }
                
            }
            else if(s[0] == 'C')
            {
                if(myqueueC.length()==0)
                    cout << "Queue C was already empty\n";
                else
                {
                    int num = myqueueC.dequeue();
                myqueueA.enqeue(num);
                cout << "Customer " << num <<" enter queue A\n";
                }
                
            }

        }
        else if(s[2]== 'r')
        {
             if(s[0] == 'B')
            {
                if(myqueueB.length()==0)
                    cout << "Queue B was already empty\n";
                else
                {
                     int num = myqueueB.dequeue();
                     myqueueC.enqeue(num);
                cout << "Customer " << num <<" enter queue C\n";
                }
            }
            else if(s[0] == 'C')
            {
                if(myqueueC.length()==0)
                    cout << "Queue C was already empty\n";
                else
                {
                    int num = myqueueC.dequeue();
                myqueueC.enqeue(num);
                cout << "Customer " << num <<" enter queue C\n";
                }
            }
        }
        getline(cin,s);
    }
    return;
}
int main()
{
   
    func<int>();
    
}