#include<iostream>
#include<vector>
#include<set>
using namespace std;

int findside(pair<int,int> leftmost, pair<int,int> rightmost, pair<int,int> current)
{
    int val = (current.second - leftmost.second) * (rightmost.first - leftmost.first) - (rightmost.second - leftmost.second)*(current.first - leftmost.first);
    if(val < 0)
    {
        return -1;
    }
    else if(val > 0)
    {
        return 1;
    }
    return 0;
}                                       
int findmaxdis(pair<int,int> leftmost, pair<int,int> rightmost, pair<int,int> current)
{
    return abs ((current.second - leftmost.second) * (rightmost.first - leftmost.first) - (rightmost.second - leftmost.second)*(current.first - leftmost.first));
}

set <pair<int,int>> fencepoints;
void findextremepoint(vector <pair<int,int>>points , int n,int leftmost, int rightmost , int side)
{
    
    int index=-1;
    int maxdis=-1;
    //cout << "leftmost " <<points[leftmost].first<<' '<<points[leftmost].second<<endl;
    //cout << "rightmost " <<points[rightmost].first<<' '<<points[rightmost].second<<endl;
    //cout << endl;
    for(int i=0; i<n; i++)
    {
        
        int temp = findmaxdis(points[leftmost], points[rightmost], points[i]);
        if(findside(points[leftmost], points[rightmost], points[i]) == side && temp > maxdis)
        {
            index = i;
            maxdis = temp;
        }

    }

    if(index ==-1)
    {
        //cout << "pushed "<<points[leftmost].first<<' '<<points[leftmost].second<<" and "<<points[rightmost].first<<' '<<points[rightmost].second<<endl << endl;
        fencepoints.insert(points[leftmost]);
        fencepoints.insert(points[rightmost]);  

         return;   
        
    }
    
        //cout << "index " <<points[index].first<<' '<<points[index].second<<endl<<endl;
        findextremepoint(points, n , index,leftmost,  -findside( points[index],points[leftmost], points[rightmost]));///
        findextremepoint(points, n, index,rightmost,  -findside( points[index], points[rightmost],points[leftmost]));///
        //findextremepoint(points, n , index,leftmost,  -1);///
        //findextremepoint(points, n, index,rightmost,  1);///      

}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n; cin >>n;
    vector <pair<int,int>> points(n);
    for(int i=0; i<n ; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    if (n < 3)
	{
		cout << "Convex hull not possible\n";
		return 0;
	}


    int leftmost=0,rightmost=0;
    for(int i=0; i<n ; i++)
    {
        if(points[i].first < points[leftmost].first)
        {
            leftmost = i;
        }
        if(points[i].first > points[rightmost].first)
        {
            rightmost = i;
        }
    }

    
    findextremepoint(points, n, leftmost, rightmost, 1);
    findextremepoint(points, n, leftmost, rightmost, -1);
    cout << "The points for fence are\n";
    while (!fencepoints.empty())
	{
		cout << "(" <<( *fencepoints.begin()).first << ", "<< (*fencepoints.begin()).second << ") ";
		fencepoints.erase(fencepoints.begin());
	}
}