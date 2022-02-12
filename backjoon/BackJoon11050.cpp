#include <iostream>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n, deno=1, nume=1;
     
    cin >> n >> k;
    while (k)
    {
        deno *= n;
        nume *= k;
        k--;
        n--;
    }

    cout << deno / nume;
  
    return 0;
}