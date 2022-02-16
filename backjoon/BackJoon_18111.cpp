#include <iostream>
#include <vector>
using namespace std;


int  answer(vector<vector<int>> ground, int layer, int b)
{
    int push = 0; //인벤토리에 넣기
    int pop = 0; //인벤토리에서 꺼내기

    for (auto its : ground)
    {
        for (auto it : its)
        {
            int tmp = it;
            if (tmp == layer) continue;

            if (tmp > layer) // 인벤토리에 넣기
            {
                push += tmp - layer;
                b += tmp - layer;
            }
            else
            {
                pop += layer - tmp;
                b -= layer - tmp;
            }
        }
    }

    if (b < 0) return -1;

    return (push * 2) + pop;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    long long int b;

    int h = 0, max = 0, min = 300;
    long long int time = 9999999999999999;
    vector<vector<int>> ground;

    cin >> n >> m >> b;
    for (int i = 0; i < n; i++)
    {
        vector<int> cnt;
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            if (min > tmp)
                min = tmp;

            if (max < tmp)
                max = tmp;
            cnt.push_back(tmp);
        }

        ground.push_back(cnt);
    }

    for (int i = min; i <= max; i++)
    {
        long long int tmp = answer(ground, i, b);
        if (tmp < 0) continue;

        if (time >= tmp)
        {
            time = tmp;
            h = i;
        }

    }


    cout << time << " " << h;
    return 0;
}