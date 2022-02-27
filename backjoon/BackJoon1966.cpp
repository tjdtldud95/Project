#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void answer()
{
    int n, m, tmp, max = 9;
    vector<int> list;
    vector<int> index;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        list.push_back(tmp);
        index.push_back(i);
    }

    int k = 0;
    while (max)
    {
        for (int i = k; i < n; i++)
        {
            if (list[i] == max)
            {
                while (list[k] != max)
                {
                    list.push_back(list[k]);
                    index.push_back(index[k]);
                    list.erase(list.begin() + k);
                    index.erase(index.begin() + k);
                }
                i = k;
                k++;
                continue;
            }

        }

        max--;
    }

    for (int i = 0; i < n; i++)
    {
        if (index[i] == m)
        {
            cout << i + 1 << "\n";
            break;
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r;
    cin >> r;

    while (r)
    {
        answer();
        r--;
    }

    return 0;
}