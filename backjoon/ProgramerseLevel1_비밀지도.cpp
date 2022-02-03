#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        string arr1Binary;
        string arr2Binary;

        int r = arr1[i];
        while (r > 0)
        {
            arr1Binary.insert(0,to_string(r%2));
            r /= 2;
        }

        while (arr1Binary.length() < n)
        {
            arr1Binary.insert(0, "0");
        }


        r = arr2[i];
        while (r > 0)
        {
            arr2Binary.insert(0, to_string(r % 2));
            r /= 2;
        }
        
        while (arr2Binary.length() < n)
        {
            arr2Binary.insert(0, "0");
        }

        string tmp;
        for (int j = 0; j < n; j++)
        {
            if (arr1Binary[j] != '0' || arr2Binary[j] != '0')
            {
                tmp.push_back('#');
                continue;
            }    

            tmp.push_back(' ');
        }

        answer.push_back(tmp);
    }

    return answer;
}

int main()
{
    solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
    
    return 0;
}