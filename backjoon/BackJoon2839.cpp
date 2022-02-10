#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n,sum=0;

    cin >> n;
    
    while (3 * sum <=n)
    {
        for (int i = 0; i <= sum; i++)
        {
            if ((3 * i) + 5 * (sum - i) == n)
                goto print;
        }
        sum++;
    }

    sum = -1;
print :
    cout << sum;
    return 0;
}