        //#include "Linked.cpp"
        #include "arrays.cpp"
#include<bits/stdc++.h>
using namespace std;

class Task2
{
    public:
    My_list Pass;

    Task2()
    {
        int K;   cin >> K ; //K is the element no
        //Pass.init(); 
        
         int X; cin >> X;
         Pass.init(K,X);      
        Pass.moveToEnd();
        for(int i=0; i<K; i++)
            {       
                int n;    cin >> n;        
                Pass.next();
                Pass.insert(n);         
                                            
            }
            Pass.moveToPos(0);     
            Pass.print(); 
    }

    void clear()
    {
        int n = Pass.length();
        while(n != 0)
        {
            Pass.remove();
            n--;
        }
        Pass.print();
        cout << "-1" << endl;
    }
    void append(int n)
    {
        // int pos  = Pass.currPos();
        // if(pos <0)
        //     pos=0;
        // Pass.moveToEnd();
        // Pass.next();
        // Pass.insert(n);        
        // Pass.moveToPos(pos);
        
        int pos  = Pass.currPos();
        if(pos <0)
            pos=0;
        int l = Pass.length();
        if(l == 0)
            Pass.insert(n);
            else
            {
                Pass.moveToPos(l-1);
                int temp = Pass.getValue();
                Pass.insert(n);
                Pass.insert(temp);
                Pass.moveToPos(l-1+2);
                Pass.remove();
                Pass.moveToPos(pos);
            }
        

        Pass.print();
        cout << "-1" << endl;
    }
    int search(int num)
    {
        int i=0;
        int n=Pass.length();
        int pos = Pass.currPos();
        Pass.moveToPos(0);
        for(int i=0; i<n ;i++)
        {
            if(num == Pass.getValue())
            {
                cout << "found"<<endl;
                Pass.moveToPos(pos);
                Pass.print();
                return i;
            }
            Pass.moveToPos(i+1);
        }
        cout << "Not found"<<endl;
        Pass.moveToPos(pos);
        Pass.print();
        return -1;

    }

};


int main()
{
    //file();
    Task2 List;
    

    int Q;
    cin >> Q;
    while(Q!=0)
    {
        if(Q==1)
        {
            List.clear();            
        }
        else if(Q==2)
        {
            int P; cin >> P;
            List.append(P);            
        }
        else if(Q==3)
        {
            int P; cin >> P;
             int n= List.search(P);
             cout << n << endl;
        }

    cin >> Q;
    }

}
