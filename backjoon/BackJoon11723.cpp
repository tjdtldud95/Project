#include <iostream>

using namespace std;


int set[20];

void answer()
{
    string order;

    cin >> order;

    if (order == "add")
    {
        int tmp;
        cin >> tmp;

        set[tmp - 1] = tmp;
    }

    else if (order == "check")
    {
        int tmp;
        cin >> tmp;

        set[tmp - 1] != 0 ? cout << 1<<"\n" : cout << 0<<"\n";
    }
    else if (order == "remove")
    {
        int tmp;
        cin >> tmp;

        set[tmp - 1] = 0;

    }
    else if (order == "toggle")
    {
        int tmp;
        cin >> tmp;

        set[tmp - 1] != 0 ? set[tmp - 1] = 0 : set[tmp - 1] = tmp;
    }
    else if (order == "all")
    {
        for (int i=0;i<20;i++)
        {
            set[i] = i + 1;
        }
    }
    else if (order == "empty")
    {
        for (int i = 0; i < 20; i++)
        {
            set[i] =0;
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