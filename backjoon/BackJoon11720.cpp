#include <iostream>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i,answer = 0;
    string r;
    cin >> i;
    cin >> r;

    i--;
    while (i>=0)
    {
        answer += (r[i] - '0');
        i--;
    }

    cout << answer;

    return 0;
}