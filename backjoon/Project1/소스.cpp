#include<iostream>
using namespace std;

int sum[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,tmp,start, end;;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        sum[i] = tmp + sum[i - 1];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;

        cout << sum[end] - sum[start-1] << "\n";
    }
    
    
    
    return 0;
}


