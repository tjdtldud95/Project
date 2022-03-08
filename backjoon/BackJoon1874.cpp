#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int index = 1;
vector<char> list;
vector<int> stack;

void answer(int value, bool &wrong )
{
    if (wrong || index >value && !stack.empty() && stack.back() <value || stack.empty() &&index > value)
    {
        wrong = true;
        return;
    }
    while (1)
    {
        if (stack.empty() ||value > stack.back() )
        {
            list.push_back('+');
            stack.push_back(index);
            index++;
        }
        else if (value == stack.back())
        {
            list.push_back('-');
            stack.pop_back();
            break;
        }

        else
        {
            list.push_back('-');
            stack.pop_back();
        }
    }
      
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r,tmp;
    bool wrong = false;
    cin >> r;

    while (r)
    {
        cin >> tmp;

        if (!wrong)
            answer(tmp,wrong);

        r--;
    }

    if (wrong)
    {
        printf("NO");
        return 0;
    }

    else
    {
        for (auto it : list)
            cout << it << "\n";
    }
       
    return 0;
}