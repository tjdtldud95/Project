#include<iostream>
#include<vector>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r, c,tmp,answer=0; cin >> r >> c;

    vector<int> list;
    while (r)
    {
        cin >> tmp;
        if (tmp> c)
        {
            list.push_back(tmp);
        }
        r--;
    }
    
    for (auto it : list)
    {
        cout << it << " ";
    }

    return 0;
}


