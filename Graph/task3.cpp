#include <bits/stdc++.h>
using namespace std;
int row, coln, horse;

vector<pair<int, int>> movements = {
    {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, -1}, {-2, -1}, {2, 1}, {-2, 1}};

bool isValid(int x, int y)
{
    return (x >= 0 && x < row && y >= 0 && y < coln);
}

int main()
{
    
    cin >> row >> coln >> horse;
    pair<int, int> startPoint[horse];
    int lev[horse][row][coln]; 
    int step[horse];

    for (int i = 0; i < horse; i++)
    {
        cin >> startPoint[i].first;
        cin >> startPoint[i].second;
        cin >> step[i];
    }

    int board[row][coln] = {};
    for (int i = 0; i < horse; i++)
    {
        int visited[row][coln] = {};
        pair<int, int> pp = startPoint[i];
        int sourcex = pp.first;
        int sourcey = pp.second;
        
        queue<pair<int, int>> q;
        q.push({sourcex, sourcey});

        board[sourcex][sourcey] +=1;
        lev[i][sourcex][sourcey] = 0;
        visited[sourcex][sourcey]=1;
        //cout << "horse " << i+1 << endl;
        //cout << sourcex <<' '<< sourcey << endl;
        while (!q.empty())
        {
            pair<int, int> v = q.front();
            int parentx = v.first;
            int parenty = v.second;
            q.pop();
            
            for (auto movement : movements)
            {
                int childx = movement.first + parentx;
                int childy = movement.second + parenty;
                if (!isValid(childx, childy))
                    continue;
                if (visited[childx][childy] == 0)
                {
                    q.push({childx, childy});
                    //cout << childx <<' ' << childy<<endl;//

                    board[childx][childy] +=1;
                    visited[childx][childy] = 1;
                    lev[i][childx][childy] = lev[i][parentx][parenty] + 1;
                }
            }           
        }
    }

    int minsteps=  INT_MAX;    
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<coln ; j++)
        {
            if(board[i][j] == horse)
            {
                int temp=0;
                //cout << "index " << i << ' ' << j<<endl;
                for(int k=0; k<horse; k++)
                {
                    double jumps = ceil(lev[k][i][j]/(double)step[k]);                                      
                    temp+= jumps;

                }
                
                minsteps= min(minsteps,temp);
            }
        }
    }
    if(minsteps == INT_MAX)
        cout << "-1" << endl;
    else
    cout << minsteps << endl;
    
}