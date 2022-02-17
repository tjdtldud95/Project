#include <iostream>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, tmp,max = 0;

    for (int i = 1; i <= 9; i++)
    {
        cin >> tmp;
        if (max < tmp)
        {
            n = i;
            max = tmp;
        }
    }

    cout << max << endl << n;
    return 0;
}