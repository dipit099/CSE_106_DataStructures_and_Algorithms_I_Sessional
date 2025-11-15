#include <bits/stdc++.h>
using namespace std;
template <typename E>
class My_list
{
private:
    E *ptr;
    int chunk_size;
    int max_size;
    int curr_index;

public:
    int front, tail, size;
    void print()
    {
        cout << "< ";
        int j = front;
        
        for (int i = 0; i < size; i++)
        {
            cout << ptr[j % max_size] << " ";
            j = (j + 1) % max_size;
        }
        cout << ">" << endl;
        return;
    }

    My_list()
    {
        curr_index = 0;
        ptr = NULL;
        size = 0;
        max_size = 1;
        front = 1;
        tail = 0;
    }

    void init()
    {
        chunk_size = sizeof(E);
        max_size = max_size * 2;
        this->ptr = (E *)realloc(ptr, (max_size)*chunk_size);
        // cout << "Allocating memory " << endl;
    }

    void insert(E n)
    {
        // cout << "Inserting element" <<endl;
        if (size == max_size - 1)
        {

            init();
        }

        ptr[(tail + 1) % max_size] = n;
        tail = (tail + 1) % max_size;

        size++;
    }

    E remove()
    {
        // cout << "Removing element" <<endl;
        if (size == 0)
        {
            cout << "No elements left in array" << endl;
            return -1;
        }
        else
        {
            E n = ptr[(front) % max_size];
            front = (front + 1) % max_size;
            size--;
            return n;
        }
    }
    void moveToStart()
    {
        // cout << "Moving current position to start" <<endl;
        curr_index = 0;
    }
    void moveToEnd()
    {
        // cout << "Moving current position to end" <<endl;
        curr_index = size - 1;
    }
    void prev()
    {
        // cout << "Moving current position one step left" <<endl;
        if (curr_index == 0)
            cout << "Current pos is already at the beginning" << endl;
        else
            curr_index--;
    }
    void next()
    {
        // cout << "Moving current position one step right" <<endl;
        if (curr_index == size)
            cout << "Current pos is already at the end" << endl;
        else
            curr_index++;
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

        this->curr_index = pos;
    }
    E getValue()
    {
        // cout << "Returning the current element" << endl;

        if (size == 0)
            return -1;
        return *(ptr + curr_index);
    }
};
