#include<iostream>
using namespace std;

long long int dp[11] = {1,1,2,4};

long long int answer(int k)
{
    if (dp[k] != 0)
        return dp[k];

    else
    {
        dp[k] = answer(k - 1) + answer(k - 2) + answer(k-3);
    }

    return dp[k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r; cin >> r;
    
    while (r)
    {
        int k;  cin >> k;
        cout << answer(k)<<"\n";
        r--;
    }


    return 0;
}


