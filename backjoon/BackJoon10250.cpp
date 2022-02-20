#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, h, w, people;
    cin >> k;

    while (k)
    {
        int answer = 0;
        int i;
        cin >> h >> w >> people;
        
        for (i = 1; i <= w; i++)
        {
            if (h * i >= people)break;
        }

        answer += (people - h * (i - 1)) * 100;
        answer += i;
        cout << answer << "\n";

        k--;
    }


    return 0;
}