#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
vector<int> adj_t[100];
int compute[100];   // sccno
int visited[60];   //if visited or not
int consider[60];   //whether that variable is present or not
vector<int> order;  //for topo sorting sequence

int sccno = 0;

void dfs1(int node)
{
    if (visited[node] == 0)
    {
        visited[node] = 1;
        for (auto adjnodes : adj[node])
        {
            if (visited[adjnodes] == 0)
            {
                // cout << node << " -> " << adjnodes << endl;
                dfs1(adjnodes);
            }
        }

        order.push_back(node);
    }
}

stack<int> mystack;
void dfs2(int node)
{
    if (visited[node] == 1)
    {        
        visited[node] = 2;
        compute[node] = sccno;
        mystack.push(node);
        for (auto adjnodes : adj_t[node])
        {
            if (visited[adjnodes] != 3)
            {
                dfs2(adjnodes);
            }
        }
    }       
    visited[node] = 3;
    // if (node % 2 == 0)
    //     cout << char(node / 2 + 'a') << ' ';
    // else
    //     cout << "~" << char(node / 2 + 'a') << ' ';
    // cout << " sccno->" << compute[node] << endl;
}

int main()
{
    //not for 91, 99 no files
    freopen("in48_.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n = 5;
    cin >> n;
    cin.ignore();

    for (int p = 0; p < n; p++)
    {
        vector<int> values;
        string line;
        getline(cin, line);
        stringstream ss(line);

        string token;
        int j = 0, temp;
        while (ss >> token)
        {
            if (token.length() == 1)
            {
                temp = (token[0] - 'a') * 2;
                values.push_back(temp);                
            }
            else
            {
                temp = (token[1] - 'a') * 2 + 1;
                values.push_back(temp);
                
            }
            j++;
            // cout << token<<' '<<temp<<endl;
            consider[temp / 2 * 2] = 1;
            consider[(temp / 2) * 2 + 1] = 1;
        }
        if (j == 2)
        {
            int a = values[0];
            int b = values[1];
            int anot = a / 2 * 2 + (1 - a % 2);
            int bnot = b / 2 * 2 + (1 - b % 2);
            
            adj[anot].push_back(b);
            adj_t[b].push_back(anot);
           
            adj[bnot].push_back(a);
            adj_t[a].push_back(bnot);
           
        }
        else
        {
            int a = values[0];
            int anot = a / 2 * 2 + (1 - a % 2);
            adj[anot].push_back(a);
            adj_t[a].push_back(anot);
        }
    }
    
    // cout << "ADj List\n\n";
    // // for(int i=start; i<size; i++)
    // for (int i = 0; i < 52; i++)
    // {
    //     if (consider[i] == 1)
    //     {
    //         if (i % 2 == 0)
    //             cout << char(i / 2 + 'a') << " -> ";
    //         else
    //             cout << "~" << char(i / 2 + 'a') <<  " -> ";
    //         for (auto itr : adj[i])
    //         {
    //             if (itr % 2 == 0)
    //                 cout << char(itr / 2 + 'a') << ' ';
    //             else
    //                 cout << "~" << char(itr / 2 + 'a') << ' ';
    //         }
    //         cout << endl;
    //     }
    // }

    for (int i = 0; i < 52; i++)
    {
        if (consider[i] == 1 && visited[i] == 0)
            dfs1(i);
    }

    // cout << "Toplogical sorting\n" << endl;
    // for (auto itr : order)
    // {
    //     if (itr % 2 == 0)
    //         cout << char(itr / 2 + 'a') << ' ';
    //     else
    //         cout << "~" << char(itr / 2 + 'a') << ' ';
    // }

    // cout << endl;
    //  for dfs2, not visited  means  value== 1, in stack  means value==2, visited means value==3
    // cout << "dfs2\n";

    while (order.size() != 0)
    {
        int node = order.back();

        order.pop_back();
        if (visited[node] == 1)
        {
            sccno++;
            dfs2(node);
        }
    }

    for (int i = 0; i < 52; i = i + 2)
    {
        if (consider[i] == 1)
        {
            if (compute[i] == compute[i + 1])
            {
                cout << "No assignment possible." << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < 52; i = i + 2)
    {
        if (consider[i] == 1)
        {
            if (compute[i] < compute[i + 1])
            {
                cout << char('a' + i / 2) << " false\n";
            }
            else
            {
                cout << char('a' + i / 2) << " true\n";
            }
        }
    }
}