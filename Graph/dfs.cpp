#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    int edge_array[vertices][edges] = {};
    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        edge_array[from][to] = 1;
    }
    int fromvertex, tovertex;
    cin >> fromvertex >> tovertex;
    int visited[vertices] = {};
    int parent[vertices] = {};
    stack<int>list;
    int currnode;
    for(int i=0; i<vertices ; i++)
    {
        if(visited[i] == 0)
        {
            visited[i]=1;
            parent[i] = -1;
            list.push(i);
            while(list.empty() != 1)
            {
                currnode = list.top();
                int gotcha=0;
                for(int j=0; j<vertices; j++)
                {
                    if(edge_array[currnode][j] == 1 && visited[j]==0)
                    {
                        visited[j] =1;
                        parent[j] = currnode;
                        list.push(j);
                        gotcha=1;
                        break;
                    }
                   
                }  
                 if(gotcha==0)
                    list.pop();              
                
                
            }

            }
        }

        // for(int i=0; i<vertices ; i++)
    //     cout<<i<<" "<<parent[i] << endl;
    stack<int> distance;
    int backnode = tovertex;
    while (backnode != -1)
    {
        distance.push(backnode);
        backnode = parent[backnode];
    }
    if (distance.top() != fromvertex)
    {
        cout << "-1" << endl;
        return 0;
    }
    else
    {
        cout << distance.size() - 1 << endl;
        while (distance.size() != 0)
        {
            cout << distance.top() << " ";
            distance.pop();
        }
    }
    
}
