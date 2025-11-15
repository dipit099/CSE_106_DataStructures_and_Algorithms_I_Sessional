#include <bits/stdc++.h>
using namespace std;

class Binary_Node
{
    int data;
    Binary_Node *left, *right;
    int count;

public:
    Binary_Node(int num, Binary_Node *bl = NULL, Binary_Node *rl = NULL)
    {
        data = num;
        left = bl;
        right = rl;
        count=1;
    }
    void setleft(Binary_Node *node)
    {
        left = node;
    }
    void setright(Binary_Node *node)
    {
        right = node;
    }
    Binary_Node *insert(int num, Binary_Node *root)
    {
        if (root == NULL)
        {
            //cout << "insert" << endl;
            root = new Binary_Node(num, NULL , NULL);
            return root;
        }
        else
        {
            if (num < root->data)
            {
                //cout << "lefting"<<endl;
                root->setleft(insert(num, root->left));
            }
            else if(num>root->data)
            {
                //cout << "righting" << endl;
                root->setright(insert(num, root->right));
            }
            else
            {
                //cout << "same" << endl;
                root->count++;
            }
            return root;
        }
    }
  
    Binary_Node *deletee(int num, Binary_Node *root)
    {

        if(root == NULL)
            return NULL;
        else
        {
            if(num< root->data)
            {
                root->setleft(deletee(num,root->left));
            }
            else if(num> root->data)
            {
                root->setright(deletee(num,root->right));
            }
            else
            {
                if(root->count > 1)
                {
                    root->count--;
                    return root;
                }
                Binary_Node *temp = root;
                if(root->left == NULL)
                {
                    root = root->right;
                    delete temp;
                }
                else if(root->right == NULL)
                {
                    root = root->left;
                    delete temp;
                }
                else
                {
                    Binary_Node *min_node = find_min(root->right);
                    root->data = min_node->data;
                    root->count--;

                    //min_node->count--; 
                    // root->setright(deletee(num, ->right));
                    root->setright(find_replace_node(root->right));
                    
                    delete min_node;
                                     

                }               

            }
             return root;
        }    
    }
    Binary_Node* find_replace_node(Binary_Node *node)
    {
        if(node->left == NULL)
            return node->right;
        else
        {
            node->setleft(find_replace_node(node->left));
            return node;
        }
        
    }
    Binary_Node* find_min( Binary_Node *head)
    {
        if(head->left == NULL)  
            return head;
        else
            return find_min(head->left);
    }
    
    int find(int num, Binary_Node *root)
    {
        if (root == NULL)
            return -1;
        else if (root->data == num)
            return root->count;
        else
        {
            if (num < root->data)
                return find(num, root->left);
            else
                return find(num, root->right);
        }
    }
    void pre_order(Binary_Node *node)
    {
        if (node != NULL)
        {
            cout << node->data ;
             if(node->count > 1)
                {
                    cout << "["<<node->count << "]";
                }
                cout << " ";

            if (node->left != NULL)
            {
                
                pre_order(node->left);
                
            }
            if (node->right != NULL)
            {
                pre_order(node->right);
            }
            
        }

    }
    void post_order(Binary_Node *node)
    {
        if (node != NULL)
        {
            
            if (node->left != NULL)
            {
                
                post_order(node->left);
                
            }
            
            if (node->right != NULL)
            {
                post_order(node->right);
            }
            cout << node->data ;
            
             if(node->count > 1)
                {
                    cout << "["<<node->count << "]";
                }
                cout << " ";
            
        }
        
    }
    void in_order(Binary_Node* node)
    {
         if (node != NULL)
        {
          if (node->left != NULL)
            {
                
                in_order(node->left);
                
            }
            cout << node->data ;
            
             if(node->count > 1)
                {
                    cout << "["<<node->count << "]";
                }
                cout << " ";
            if (node->right != NULL)
            {
                in_order(node->right);
            }
            
        }

    }
    void print(Binary_Node *root)
    {
        cout << root->data ; 
        if(root->count >1 )
        cout << "["  <<root->count<<"]";      
        if(root->left == NULL && root->right == NULL){}            
        else
        { 
            cout << "(";       
            
            if(root->left != NULL)
            {
                print(root->left);
            }
            cout << ",";
            if(root->right != NULL)
            {
                print(root->right);
            }
            cout<< ")";           

        }        
    }
    
};
// int find_num(int *arr,int count, int number)
// {
//     for(int i=0; i< count; i++)
//     {
//         if(arr[i] == number)
//         {
//             return i;
            
//         }
//     }
//     return -1;
// }

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    Binary_Node *head = NULL;
    string s;
    getline(cin, s);
    
    


    while (s != "0")
    {
        if (s[0] == 'I')
        {            
            int num=0;
            for(int i=2; s[i]!='\0'; i++)
            {
                num = num*10 + s[i]-'0';
            }         

           
                head = head->insert(num, head);                            
             cout <<"(";
            head->print(head);
            cout <<")";
          
            cout << endl;
        }
        else if (s[0] == 'D')
        {
            
            int num=0;
            for(int i=2; s[i]!='\0'; i++)
            {
                num = num*10 + s[i]-'0';
            }
           
            
                head = head->deletee(num, head);
                
            
           
            cout <<"(";
            if(head != NULL)
            head->print(head);
            cout <<")";
            cout << endl;

        }
        else if (s[0] == 'F')
        {
            int num=0;
            for(int i=2; s[i]!='\0'; i++)
            {
                num = num*10 + s[i]-'0';
            }
            int store=head->find(num,head);
            if(store != -1)
            {
                cout << "found " << store << endl;                
           

            }
                
            else
                cout<< "not found" << endl;
        }

        else if (s[0] == 'T')
        {
            string temp="";
            for(int i=2; s[i]!='\0'; i++)
            {
                temp += s[i];
            }
            if(temp == "Pre")
            {
                head->pre_order(head);
                cout << endl;
            }
            else if(temp == "Post")
            {
                head->post_order(head);
                cout << endl;
            }
            else if(temp == "In")
            {
                head->in_order(head);
                cout << endl;
            }


        }
        else
        {

            
            cout << "invalid input\n"; 
        }
        getline(cin, s);
    }
}