#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n,a; 
    
    cin >> n;
    vector<int> list (n+1,0);

    for (int i = 2; i <= n;i++)
    {
        if (i < 4)
        {
            list[i] = 1;
            continue;
        }
        int value = INT_MAX;
        if (i % 3 == 0)
        {
            value = min(value, list[i / 3]);
        }

        if (i % 2 == 0)
        {
            value = min(value, list[i / 2]);
        }

        value = min(value, list[i - 1]);
        
        list[i] = value+1;
    }

    cout << list[n];




    return 0;
}


