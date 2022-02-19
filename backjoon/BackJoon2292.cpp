#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, between = 1, cal = 0;
    cin >> i;


    while (i > between)
    {
        between += (6 * ++cal);
    }


    cout << cal + 1;

    return 0;
}