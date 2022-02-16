#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n, k, mid, tmp, low, high;
    vector<int> value;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        value.push_back(tmp);

    }

    sort(value.begin(), value.end());

    high = value.back();
    low = 1;

    while (low <= high)
    {
        long long int sum = 0;
        mid = (high + low) / 2;

        for (auto it : value)
        {
            if (it < mid) continue;

            sum += it - mid;
        }

        if (sum >= k)
            low = mid + 1;

        else
            high = mid - 1;

    }

    cout << high;


    return 0;
}