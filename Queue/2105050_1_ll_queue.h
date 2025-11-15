#include <bits/stdc++.h>
using namespace std;
template <typename E>
class Node
{
public:
    Node *next;
    E data;
    Node()
    {
        this->next = NULL;
    }
};

template <typename E>
class My_list
{
private:
    Node<E> *head;
    Node<E> *tail;
    Node<E> *past_node;
    Node<E> *new_node;
    Node<E> *curr_node;
    int curr_index;
    int size;

    void find(int curr_index)
    {
        Node<E> *temp = head;
        past_node = NULL;
        for (int i = 0; i < size; i++)
        {
            if (i == curr_index)
            {
                curr_node = temp;
                return;
            }
            past_node = temp;
            temp = temp->next;
        }
    }

public:
    void print()
    {
        Node<E> *temp = head;
        cout << "< ";

        for (int i = 0; i < size; i++)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << ">" << endl;

        return;
    }

    My_list()
    {
        size = 0;
        curr_index = 0;
        head = NULL;
        past_node = NULL;
        new_node = NULL;
        curr_node = NULL;
        tail = NULL;
    }

    void init()
    {
        new_node = (Node<E> *)malloc(sizeof(Node<E>));
        if (new_node == NULL)
        {
            printf("Cant create a new node");
            exit(1);
        }
    }

    void insert(E n)
    {
        // cout << "Inserting element" <<endl;

        init();
        if (head == NULL)
        {
            new_node->data = n;
            head = new_node;
            curr_node = head;
            curr_index = 0;
            past_node = NULL;
            size++;
            tail = head;
        }
        else
        {
            new_node->data = n;
            tail->next = new_node;
            tail = tail->next;
            size++;
        }
    }

    E remove()
    {
        // cout << "Removing element" <<endl;
        if (size == 0)
        {
            cout << "No elements left" << endl;
            return -1;
        }
        else if (size == 1)
        {
            int n = head->data;
            Node<E> *temp = head;
            head = NULL;
            free(temp);
            size--;
            tail = NULL;
            return n;
        }
        int n = head->data;
        Node<E> *temp = head;
        head = head->next;
        free(temp);
        size--;
        return n;
    }
    void moveToStart()
    {
        // cout << "Moving current position to start" <<endl;
        curr_index = 0;
        find(curr_index);
    }
    void moveToEnd()
    {
        // cout << "Moving current position to end" <<endl;
        curr_index = size - 1;
        find(curr_index);
    }
    void prev()
    {
        // cout << "Moving current position one step left" <<endl;
        if (curr_index == 0)
            cout << "Current pos is already at the beginning" << endl;
        else
        {
            curr_index--;
            find(curr_index);
        }
    }
    void next()
    {
        // cout << "Moving current position one step right" <<endl;

        {
            curr_index++;
            find(curr_index);
        }
    }

    int length()
    {
        // cout << "Finding length = "<<endl  ;
        return this->size;
    }
    int currPos()
    {
        // cout << "Returning the position "  <<endl;
        return this->curr_index;
    }
    void moveToPos(int pos)
    {
        // cout << "Moving current position" <<endl;
        if (pos < size)
        {
            this->curr_index = pos;
            find(curr_index);
        }
    }
    E getValue()
    {
        // cout << "Returning the current element" << endl;

        if (size == 0)
            return -1;

        return curr_node->data;
    }
};
