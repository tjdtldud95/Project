#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool isword;
    string tmp;
    int answer = 0;

    getline(cin, tmp);

    for (int i = 1; i <= tmp.size(); i++)
    {
        if (tmp[i] == ' ' && tmp[i-1] != ' ' || tmp[i] == '\0' && tmp[i - 1] != ' ')
        {
            answer++;
        }
    }
    
    cout << answer;

    return 0;
}