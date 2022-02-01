#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    if (s.length() % 2 != 0 || s.empty())
        return false;
    
    int count = 0;
    for (auto it : s)
    {
        if (it == '(') count++;

        else
            count--;


        if (count < 0) return false;
    }

    if (count != 0) return false;
 
    return true;
}

int main()
{
   cout<< solution(")(");
    return 0;
}