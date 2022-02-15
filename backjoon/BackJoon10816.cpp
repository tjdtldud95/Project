#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,tmp;
    vector<int> list;
    vector<int> search;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        list.push_back(tmp);
    }
    
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        search.push_back(tmp);
    }

    sort(list.begin(), list.end());

    for (auto it : search)
    {
        auto min = lower_bound(list.begin(), list.end(), it);
        auto max = upper_bound(list.begin(), list.end(), it);
        cout << max -min << " ";
    }





    return 0;
}