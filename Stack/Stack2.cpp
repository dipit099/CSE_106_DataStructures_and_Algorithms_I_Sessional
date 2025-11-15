#include <iostream>
#include <string>
#include"Stack0.cpp"
using namespace std;

int main()
{
    string str;
    cin >> str;
     int length = str.size();

    Stack<char> valid_check(length);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
            valid_check.push(str[i]);
        else if (str[i] == ')')
        {
            if (valid_check.length() > 0)
            {
                valid_check.pop();
            }
            else
            {
                cout << "Not valid\n";
                return 0;
            }
        }
    }
    if (valid_check.length() != 0)
    {
        cout << "Not valid\n";
        return 0;
    }
    int check = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '(' || str[i] == ')')
        {
            check = 0;
        }
        else
        {
            if (check == 1)
            {
                cout << "Not valid\n";

                return 0;
            }
            else if (i == str.size() - 1)
            {
                cout << "Not valid\n";

                return 0;
            }
            else
            {
                check = 1;
            }
        }
    }

    Stack<char> mystack1(length);
    Stack<float> mystack2(length);    
    int found = 0;

    int prec = 0;
   
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {

            if (str[i] != ')')
            {
                if (str[i] == '-' && str[i - 1] == '(')
                    found = 1;
                else
                    mystack1.push(str[i]);
            }

            else if (str[i] == ')')
            {
                while (mystack1.topValue() != '(')
                {
                    float temp = mystack2.pop();
                    if (mystack1.topValue() == '+')
                    {
                        temp = temp + mystack2.pop();
                        mystack1.pop();
                    }
                    else if (mystack1.topValue() == '-')
                    {
                        temp = mystack2.pop() - temp;
                        mystack1.pop();
                    }
                    mystack2.push(temp);
                    // mystack1.print();
                    // mystack2.print();
                }
                mystack1.pop();
                if (mystack1.topValue() == '*' || mystack1.topValue() == '/')
                {
                    float temp = mystack2.pop();
                    if (mystack1.topValue() == '*')
                    {
                        temp = temp * mystack2.pop();
                        mystack1.pop();
                    }
                    else if (mystack1.topValue() == '/')
                    {
                        if(temp == 0)
                            {
                                printf("Invalid expression found\n");                                
                                return 0;
                            }
                        temp = mystack2.pop() / temp;
                        mystack1.pop();
                    }
                    mystack2.push(temp);
                }
                prec = 0;
            }
        }

        else
        {
            float temp = 0;

            while (str[i] >= '0' && str[i] <= '9')
            {
                temp = temp * 10 + str[i] - '0';
                i++;
            }
            i--;
            if (found == 1)
                mystack2.push(temp * (-1));
            else
                mystack2.push(temp);
            found = 0;

            // mystack1.print();
            // mystack2.print();
            if (prec == 3)
            {
                float temp = mystack2.pop();
                if (mystack1.topValue() == '*')
                {
                    temp = temp * mystack2.pop();
                    mystack1.pop();
                }
                else if (mystack1.topValue() == '/')
                {
                     if(temp == 0)
                            {
                                printf("Invalid expression found\n");                                
                                return 0;
                            }
                    temp = mystack2.pop() / temp;
                    mystack1.pop();
                }
                mystack2.push(temp);
            }
        }

        if (mystack1.topValue() == '*' || mystack1.topValue() == '/')
        {
            prec = 3;
        }
        else if (mystack1.topValue() == '+' || mystack1.topValue() == '-')
        {
            prec = 1;
        }
        else if (mystack1.topValue() == '(')
        {
            prec = 0;
        }
        // mystack1.print();
        // mystack2.print();
    }

    while (mystack1.length() != 0)
    {
        float temp = mystack2.pop();
        if (mystack1.topValue() == '+')
        {
            temp = temp + mystack2.pop();
            mystack1.pop();
        }
        else if (mystack1.topValue() == '-')
        {
            temp = mystack2.pop() - temp;
            mystack1.pop();
        }
        mystack2.push(temp);
    }
    // mystack1.print();
    // mystack2.print();
    float ans = mystack2.pop();
    cout << "Valid expression" <<endl;
    cout << "Computed value = " << ans << endl;
}