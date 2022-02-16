#include <iostream>
#include <vector>
using namespace std;

vector<int> queue;

void  answer(const string& order)
{
    if (order.compare("push") == 0)
    {
        int tmp;
        cin >> tmp;
        queue.push_back(tmp);
    }
    else if (order.compare("pop") == 0)
    {
        if (queue.empty())
            cout << -1 << "\n";
        else
        {
            cout << queue.front() << "\n";
            queue.erase(queue.begin());
        }

    }
    else if (order.compare("front") == 0)
    {
        if (queue.empty())
            cout << -1 << "\n";

        else
            cout << queue.front() << "\n";
    }
    else if (order.compare("back") == 0)
    {
        if (queue.empty())
            cout << -1 << "\n";
        else
            cout << queue.back() << "\n";
    }
    else if (order.compare("size") == 0)
    {
        cout << queue.size() << "\n";
    }
    else if (order.compare("empty") == 0)
    {
        if (queue.empty())
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string order;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> order;
        answer(order);
    }

    return 0;
}