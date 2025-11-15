#include <bits/stdc++.h>
using namespace std;

class Binary_Node
{
    int data;
    Binary_Node *left, *right;

public:
    Binary_Node(int num, Binary_Node *bl = NULL, Binary_Node *rl = NULL)
    {
        data = num;
        left = bl;
        right = rl;
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
            else
            {
                //cout << "righting" << endl;
                root->setright(insert(num, root->right));
            }
            return root;
        }
    }
    Binary_Node* node_link(int num, Binary_Node *root)
    {
         if (root == NULL)
            return NULL;
        else if (root->data == num)
            return root;
        else
        {
            if (num < root->data)
                return node_link(num, root->left);
            else
                return node_link(num, root->right);
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
    
    bool find(int num, Binary_Node *root)
    {
        if (root == NULL)
            return false;
        else if (root->data == num)
            return true;
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
            cout << node->data <<" ";
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
            cout << node->data <<" ";
            
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
            cout << node->data <<" ";
            if (node->right != NULL)
            {
                in_order(node->right);
            }
            
        }

    }
    void print(Binary_Node *root)
    {
        cout << root->data ;        
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
            //cout << num;
            head = head->insert(num, head);
            cout <<"(";
            head->print(head);
            cout <<")";
            cout << endl;
        }
        else if (s[0] == 'D')
        {
            //cout << "delete" << endl;
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
            if(head->find(num,head))
                cout << "found" << endl;
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