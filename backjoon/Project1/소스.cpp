#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int list[1000] = { 0 };
    int tmp,answer = 0;

    for (int i = 0; i < 10; i++)
    {
        cin >> tmp;
        list[tmp % 42]++;
    }

    for (auto it : list)
    {
        if (it != 0)
            answer++;
    }

    cout << answer;
    return 0;
}


