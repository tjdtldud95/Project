#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> list;
    vector<int> search;

    int r,tmp;

    cin >> r;
    for (int i = 0; i < r; i++)
    {
        cin >> tmp;
        list.push_back(tmp);
    }

    cin >> r;
    for (int i = 0; i < r; i++)
    {
        cin >> tmp;
        search.push_back(tmp);
    }

    sort(list.begin(), list.end());
    
    for (auto i : search)
    {
        binary_search(list.begin(), list.end(), i) ? cout << "1\n" : cout << "0\n";
    }

    return 0;
}