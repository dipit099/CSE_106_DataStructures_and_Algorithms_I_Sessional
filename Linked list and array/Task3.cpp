  //#include "arrays.cpp"
    #include "Linked.cpp"
#include<bits/stdc++.h>
using namespace std;
 int X,Y,Z;   

int request(My_list &Garage)
{
    Garage.moveToPos(0);
    int done=0, index= -1;
    if(Garage.length() > 0 )
    {
         int min = Garage.getValue();
        for(int i=0; i<Garage.length(); i++)
        {  
            if(Garage.getValue() <= min )  
               {
                    min =  Garage.getValue();
                    index = i;
               }      
            Garage.next();
        }
        Garage.moveToPos(index);
        Garage.remove();
        return 1;
    }
    return 0;
    

}
int rent(My_list &Garage, int car)
{
    Garage.moveToPos(0);
    int done=0, index= -1;
    if(Garage.length() < Z)
    {
         int max = Garage.getValue();
        for(int i=0; i<Garage.length(); i++)
        {  
            if(Garage.getValue() >= max )  
               {
                    max =  Garage.getValue();
                    index = i;
               }      
            Garage.next();
        }
        Garage.moveToPos(index);
        Garage.next();
        Garage.insert(car);
        return 1;
    }
    return 0;
}


int main()
{  
     
    cin >> X >> Y >> Z;
    My_list Garage[Y];
    string str;   
    
    int n,temp;
    for(int i=0; i<Y; i++)
    {            
        int arr[Z],j=0;
        cin >> n;
        getline(cin, str);
        istringstream my_s(str);       
            while( my_s >> temp)
            {             
                 arr[j] = temp;
                j++;                
            }        
        //Garage[n-1].init(j,4);
        Garage[n-1].init();
        Garage[n-1].moveToEnd();
        for(int k=0; k<j; k++)
        {                     
            Garage[n-1].next();
            Garage[n-1].insert(arr[k]);         
                                        
        }
        Garage[n-1].moveToPos(0);
       
    }
    cout << endl << endl;
    for(int i=0; i<Y; i++)
    {
        Garage[i].print_car();         
    }

    string arr;
    cin >> arr;
    while( arr != "end")
    {
        if(arr == "req")
        {
            int m;
            for(int i=0; i<Y; i++)
            {
                m = request(Garage[i]);
                if(m==1)
                    break;
            }
            if(m==0)
            {
                cout << "No cars are available!!!" << endl;
            }
        }
        else if( arr == "ret")
        {
            int car;
            cin >> car;
            int m;
            for(int i=Y-1; i>=0; i--)
            {
                m = rent(Garage[i],car);
                if(m==1)
                    break;
            }
            if(m==0)
            {
                cout << "All garages are full !!!" << endl;
            }
        }        
        for(int i=0; i<Y; i++)
        {
            Garage[i].print_car();         
        }
        cin >> arr;
    }
    



}