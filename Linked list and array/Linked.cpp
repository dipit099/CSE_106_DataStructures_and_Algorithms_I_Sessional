#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
        Node *next;
        int data;
}Node;

class My_list
{
    private:
    Node *head;
    Node *past_node;
    Node *new_node;
    Node *curr_node;
    int curr_index;
    int size;       
        
    void find(int curr_index)
    {
          Node *temp = head;
          past_node= NULL;
          for(int i=0; i<size ; i++)
         {
            if(i==curr_index)
            {
               curr_node= temp; 
               return;
            }  
            past_node = temp;
            temp = temp->next;                      
            
        }  

    }

    public: 
    void print()
    { 
        Node *temp=head;
        cout << "< ";

        for(int i=0; i<size ; i++)
        {
            if(curr_index==i)
            {
                cout <<'|';
            }
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout <<">"<<endl; 
                
        return;
    }
    void print_car()
    { 
        Node *temp=head;       

        for(int i=0; i<size ; i++)
        {            
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;                
        return;
    }
     My_list()
    {
        size=0;
        curr_index = 0;
        head = NULL; 
        past_node= NULL;
        new_node= NULL;
        curr_node= NULL;     
    }
    
    
    void init()
    {                    
            new_node = (Node*)malloc(sizeof(Node));
            new_node->next= NULL;
            if(new_node== NULL)
            {
                printf("Cant create a new node");
                exit(1);
            }          
                             
    }     

    
    void insert(int n)           //Inserts an element at the current location
    {   
        //cout << "Inserting element" <<endl; 

        init(); 
        if(head == NULL)
        {
            new_node->data = n;
            head = new_node;
            curr_node= head;            
            curr_index=0;  
            past_node = NULL;          
            size++;
        }
        else if(curr_index==0)
        {
            new_node->data = n;
            new_node->next = head;
            head = new_node;    
            curr_node = head;
            past_node = NULL;       
            size++;
        }
        else
        { 
            new_node->data = n;           
            new_node->next = curr_node;
            past_node->next= new_node;
            curr_node = new_node;
            size++;
        }
        
    }

    int remove()                            //remove current element
    {
       //cout << "Removing element" <<endl;
       if(size==0)
        {
            cout << "No elements left" <<endl;
            return -1;
        }
       int n=curr_node->data;
       if(curr_node== head)
       {
        head = head->next;
        curr_node=head;
        size--;
       }
       else
       {
        past_node->next = curr_node->next;    
        size--;
       }
       if(curr_index==size)
       {        
        curr_index--;
        
       }
       find(curr_index);
       if(curr_index==-1)
        head = NULL;
       return n;
    }
    void moveToStart() 
    {
        //cout << "Moving current position to start" <<endl;
        curr_index=0;
        find(curr_index);       
       
    }
    void moveToEnd()
    {
        //cout << "Moving current position to end" <<endl;
        curr_index= size-1;
        find(curr_index);       
       
    }
    void prev() 
    {
        //cout << "Moving current position one step left" <<endl;
        if(curr_index==0)
            cout << "Current pos is already at the beginning"<<endl;
        else
            {
                curr_index--;
                find(curr_index);
            }
       
    }
    void next()
    {
        //cout << "Moving current position one step right" <<endl;
        if(curr_index==size)
            cout << "Current pos is already at the end"<<endl;
        else
            {
                curr_index++;
                find(curr_index);
            }
        
       
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
        {
             this->curr_index = pos;
            find(curr_index);
        }
       
      
       
    }
    int getValue()          //Return the current element.
    {
        //cout << "Returning the current element" << endl;
      
        if(curr_index == -1)
            return -1;
        
        return curr_node->data;
    }
    
    

};
