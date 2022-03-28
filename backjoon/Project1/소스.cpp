#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r; cin >> r;
    
    for (int i = 1; i <= 9; i++)
    {
        cout << r << " * " << i << " = " << r*i<<"\n";
    }
    return 0;
}


