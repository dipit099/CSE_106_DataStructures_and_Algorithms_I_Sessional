#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
     if(a.second == b.second)
            return a.first<b.first;   // bot same hole then 1st element jar boorro hbe
    return a.second < b.second;             // naile 2nd element jar choto hbe
    // Compare based on second element
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    vector<pair<int,int>>vp(n);
    for(int i=0; i<n ; i++)
    {
        cin >> vp[i].first;
        cin >> vp[i].second;
    }
    sort(vp.begin(),vp.end(),compare);
    vector<int>endtime;
    endtime.push_back(vp[0].second);    //first done
    for(int i=1; i<n ; i++)
    {
        int add=1;
        for(int j=0; j<endtime.size(); j++)
        {
            if(vp[i].first>=endtime[j])
            {
                add=0;
                endtime[j] = vp[i].second;
                break;
            }
        }
        if(add==1)
        {
            endtime.push_back(vp[i].second);
        }
    }
    // for(auto itr: endtime)
    // {
    //     cout << itr << endl;
    // }
    cout << endtime.size() << endl;

}