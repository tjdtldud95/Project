#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int min, max;
    bool isDecimal;
    vector<int> answer = { 2,3 };

    cin >> min >> max;

    for (int i = 5; i <= max; i++)
    {
        isDecimal = true;
        if (i % 2 == 0 || i == 1)
        {
            continue;
        }

        for (auto it : answer)
        {
            if ((it * it) > i)
                break;

            if (i % it == 0)
            {
                isDecimal = false;
                break;
            }
        }

        if (isDecimal)
            answer.push_back(i);
    }

    for (auto it : answer)
    {
        if (it < min) continue;
        if (it > max) break;
        cout << it << "\n";
    }

    return 0;
}