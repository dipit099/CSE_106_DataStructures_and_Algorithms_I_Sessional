#include <bits/stdc++.h>
using namespace std;

template <typename E>
class Priority_Queue
{
    E *arr;
    int max_size;
    int size;

private:
    void max_heapify(int index)
    {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int maxa;
        if (left < size && arr[left] > arr[index])
        {
            maxa = left;
        }
        else
            maxa = index;
        if (right < size && arr[right] > arr[maxa])
        {
            maxa = right;
        }
        if (index != maxa)
        {
            swap(arr[index], arr[maxa]);
            max_heapify(maxa);
        }
    }
    void init()
    {
        if (size >= max_size)
        {
            max_size = (max_size + 1) * 2;

            arr = (E *)realloc(arr, max_size * sizeof(E));
        }
    }

public:
    Priority_Queue()
    {
        arr = NULL;
        max_size = 0;
        size = 0;
    }
    void insert(E num)
    {
        init();
        arr[size] = INT_MIN;
        increase_key(size, num);

        size++;
    }
    bool increase_key(int index, E key)
    {
        if (key > arr[index])
        {

            arr[index] = key;
            int child = index, parent = (child - 1) / 2;
            while (child > 0 && arr[parent] < arr[child])
            {

                swap(arr[parent], arr[child]);

                child = parent;
                parent = (child - 1) / 2;
            }
            return true;
        }

        return false;
    }
    bool decrease_key(int index, E key)
    {
        if (key < arr[index])
        {
            arr[index] = key;
            max_heapify(index);

            return true;
        }

        return false;
    }

    E find_max()
    {
        if (size > 0)
        {
            return arr[0];
        }
        else
        return INT_MIN;
    }
    E extract_max()
    {
        if(size>0)
        {
            E temp = arr[0];
            arr[0] = arr[size - 1];
            size--;
            max_heapify(0);
            return temp;
        }
        else
        return INT_MIN;
        
    }
    void print()
    {
        int index = 0, j = 1;

        cout << "No of elements: " << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "   ";
            if (i == index)
            {
                cout << endl;
                index = index + j * 2;
                j = j * 2;
            }
        }
        cout << endl;
    }

    void sorting()
    {
        int temp_size = size;
        for (int i = 0; i + 1 < size; )
        {
            swap(arr[size - 1], arr[0]);
            size--;
            max_heapify(0);
        }
        size = temp_size;

        print();
    }
};

template <typename E>
void func()
{
    Priority_Queue<E> my_ppq;

    int n;
    cin >> n;
    while (n != 7)
    {
        if (n == 1)
        {
            E p;
            cin >> p;
            my_ppq.insert(p);
        }
        else if (n == 2)
        {
            E num = my_ppq.find_max();
            cout << "Max: " << num << endl;
        }
        else if (n == 3)
        {
            E num = my_ppq.extract_max();
            cout << "Max: " << num << " has been extracted." << endl;
        }
        else if (n == 4)
        {
            int index;
            cin >> index;
            int p;
            cin >> p;
            if (my_ppq.increase_key(index - 1, p) == true)
                cout << "Key increased!\n";
            else
                cout << "New key is not larger than the previous key\n";
        }
        else if (n == 5)
        {
            int index;
            cin >> index;
            int p;
            cin >> p;
            if (my_ppq.decrease_key(index - 1, p) == true)
                cout << "Key decreased!\n";
            else
                cout << "New key is not smaller than the previous key\n";
        }

        else if (n == 6)
        {
            my_ppq.print();
        }
        else
        {

            cout << "Invaliddd key\n";
        }
        cin >> n;
    }
    my_ppq.sorting();
}
int main()
{
    freopen("in2.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    func<int>();
    return 0;
}