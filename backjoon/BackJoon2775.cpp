#include <iostream>

using namespace std;

int answer(int floor , int number)
{
    if(number ==1)
        return 1;

    if (floor == 0)
        return number;

    return answer(floor, number - 1) + answer(floor - 1, number);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r,k, n;

    cin >> r;

    while (r)
    {
        cin >> k >> n;
        cout << answer(k, n) << "\n";
        r--;
    }
  
    return 0;
}