#include<iostream>
#include<vector>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r; cin >> r;

    for (int i = 0; i < r; i++)
    {
        for (int j = r-1; j > i; j--)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        cout<<"\n";
    }

    return 0;
}


