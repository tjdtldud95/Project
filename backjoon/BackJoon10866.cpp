#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector <int> deck;

void answer(string order)
{
    int value;
    if (order == "push_back")
    {
        cin >> value;
        deck.push_back(value);
    }

    else if (order == "push_front")
    {
        cin >> value;
        deck.insert(deck.begin(), value);
    }

    else if (order == "pop_front")
    {
        if (deck.empty())
        {
            cout << -1 << "\n";
            return;
        }
        cout << deck.front() << "\n";
        deck.erase(deck.begin());
    }
    else if (order == "front")
    {
        if (deck.empty())
        {
            cout << -1 << "\n";
            return;
        }
        cout << deck.front() << "\n";
    }

    else if (order == "back")
    {
        if (deck.empty())
        {
            cout << -1<<"\n";
            return;
        }
        cout << deck.back() << "\n";
    }

    else if (order == "pop_back")
    {
        if (deck.empty())
        {
            cout << -1 << "\n";
            return;
        }
        cout << deck.back() << "\n";
        deck.pop_back();
    }
    else if (order == "empty")
    {
        deck.empty() ? cout << 1 << "\n" : cout << 0 << "\n";
    }

    else if (order == "size")
    {
        cout << deck.size() << "\n";
    }

 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r;
    string order;
    cin >> r;

    while (r)
    {
        cin >> order;
        answer(order);
        r--;
    }
  
    return 0;
}