#include <iostream>
#include <vector>

using namespace std;


int GCD(int a, int b)
{
    if (b == 0) return a;

    return GCD(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    int gcd;
    cin >> k >> n;

    if (k > n)
        gcd = GCD(k, n);
    else
        gcd = GCD(n, k);

    cout << gcd << "\n";
    cout << k * n / gcd;

    return 0;
}