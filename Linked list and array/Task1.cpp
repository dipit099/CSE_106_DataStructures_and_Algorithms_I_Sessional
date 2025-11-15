 #include "arrays.cpp"
//   #include "Linked.cpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{    
   
    int K;                      //K is the element no
    cin >> K;
    int X;   cin >> X;

    My_list list;

    //list.init();
    list.init(K,X);
    
    list.moveToEnd();
    for(int i=0; i<K; i++)
    {       
        int n;    
        cin >> n;        
        list.next();
        list.insert(n);         
                                    
    }
    list.moveToPos(0);  
    list.print();   
    
    int Q;
    cin >> Q;
    while(Q!=0)
    {
        if(Q==1)
        {
            int P;  cin >> P;
            list.insert(P);
            list.print();
            cout << "-1" << endl;            
        }
        else if(Q==2)
        {
             int n =list.remove();
             list.print();
             cout << n << endl;
        }
        else if(Q==3)
        {
             list.moveToStart();
             list.print();
             cout << "-1" << endl;
        }
        else if(Q==4)
        {
             list.moveToEnd();
             list.print();
             cout << "-1" << endl;
        }
        else if(Q==5)
        {
            list.prev();
            list.print();
            cout << "-1" << endl;
        }
        else if(Q==6)
        {
             list.next();
             list.print();
             cout << "-1" << endl;
        }
        else if(Q==7)
        {
             int n =list.length();
             cout << n << endl;
        }
        else if(Q==8)
        {
            int n = list.currPos();
            list.print();
            cout << n << endl;
        }
        else if(Q==9)
        {
            int P; cin >> P;
             list.moveToPos(P);
             list.print();
             cout << "-1" << endl;
        }
        else if(Q==10)
        {
             int n =list.getValue();
             list.print();
             cout << n << endl;
        }
        cin >> Q;
    }    
   

    

}
