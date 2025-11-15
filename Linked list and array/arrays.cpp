#include<bits/stdc++.h>
using namespace std;
class My_list
{
    private:
        int *ptr;        
        int chunk_size;
        int size;
        int max_size; 
        int curr_index;         


    public: 
    
     void print()
    {    
        cout << "< ";
        for(int i=0; i<size ; i++)
        {
            if(curr_index==i)
            {
                cout <<'|';
            }
            cout << ptr[i] << " ";
        }    
        cout <<">"<<endl; 
        return;     
    }
    void print_car()
    {    
        
        for(int i=0; i<size ; i++)
        {            
            cout << ptr[i] << " ";
        }    
        cout << endl;
        return;     
    }
    
    My_list() {        
        curr_index = 0;
        ptr = NULL;
        size = 0;
        max_size=0;
    }
    
    
    void init(int K, int X)
    { 
        max_size = K;  
        chunk_size= X; 
        this->ptr=(int*)realloc(ptr,max_size*chunk_size);
        //cout << "Allocating memory " << endl;
              
    }     

    
    void insert(int n)           //Inserts an element at the current location
    { 
        //cout << "Inserting element" <<endl;        
        
        if(size==0)
        {                        
             *(ptr)=n;
             curr_index=0;
             size++;            
             return;
        } 
        else if(size == max_size)                          
                {
                    max_size = max_size*2; 
                    init(max_size,chunk_size);                     
                }        
        for(int i=size-1; i>=curr_index; i--)
        {
            *(ptr+i+1)=*(ptr+i);
        }
        *(ptr+curr_index) = n;
        size++;       
       
    }

    int remove()                    //remove current element
    {
        //cout << "Removing element" <<endl;
        if(size==0)
        {
            cout << "No elements left in array"<<endl;
            return -1;
        }
        int n= *(ptr+curr_index);
        
        for(int i=curr_index; i<size-1; i++)
        {
            *(ptr+i)=*(ptr+i+1);
        }
        if(curr_index== size-1)
            curr_index--;
        size--;       
        return n;
    }
    void moveToStart() 
    {
        //cout << "Moving current position to start" <<endl;
        curr_index=0;      
       
    }
    void moveToEnd()
    {
        //cout << "Moving current position to end" <<endl;
        curr_index= size-1;       
       
    }
    void prev() 
    {
        //cout << "Moving current position one step left" <<endl;
        if(curr_index==0)
            cout << "Current pos is already at the beginning" << endl;
        else
            curr_index--;        
                
    }
    void next()
    {
        //cout << "Moving current position one step right" <<endl;
        if(curr_index==size)
            cout << "Current pos is already at the end"<< endl;
        else
            curr_index++;      
       
    }    
    
    int length()
    {
        //cout << "Finding length = "<<endl  ;
        return this->size;
    }
    int currPos()   //Return the position (in the list) of the current element.
    {
        //cout << "Returning the position "  <<endl;        
        return this->curr_index;        
    }
    void moveToPos(int pos)      //Set current position.
    {
        //cout << "Moving current position" <<endl;
        if(pos <size)
            this->curr_index = pos;
        
       
    }
    int getValue()          //Return the current element.
    {
        //cout << "Returning the current element" << endl;
        
        if(curr_index == -1)
            return -1;        
        return *(ptr+curr_index);
    }
    

};



 
   
      