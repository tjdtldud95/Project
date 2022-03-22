#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string tmp;
    int r, m;

    cin >> r;
    while (r)
    {
        cin >> m;
        cin >> tmp;
        for (auto it : tmp)
        {
            for (int i = 0; i < m; i++)
            {
                cout << it;
            }
        }
        cout << "\n";
        r--;
    }
    
    return 0;
}


