#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    set<int> list;
  
    int len = 1;
    while (len <=numbers.size())
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            string tmp = "";
            tmp += numbers[i];
            for (int j = 0; j < numbers.size(); j++)
            {
                if (i == j) continue;

                if (tmp.size() >= len)
                {
                    list.insert(stoi(tmp));
                    tmp.pop_back();
                    continue;
                }

                tmp.push_back(numbers[j]);
                if (tmp.size() >= len)
                {
                    list.insert(stoi(tmp));
                    tmp.pop_back();
                }
            }

        }

        len++;
    }


    for (auto it : list)
    {
        cout << it << " ";
        if (it % 2 == 0 && it!=2|| it ==0 ||it==1) continue; // Â¦¼ö

        if (it == 2)
        {
            answer++;
            continue;
        }

        int i = 3;
        bool isDec = true;
        while (i*i <it)
        {
            if (it % i == 0)
            {
                isDec = false;
                break;
            }
                
            i++;
        }

        if (isDec) answer++;
    }

    cout << "\n";
    return answer;
}
/*

int main()
{
   cout << solution("1234");

    return 0;
}
*/