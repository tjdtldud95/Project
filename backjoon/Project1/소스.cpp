#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


vector<int> solution(int n, vector<int> info)
{
	vector<int> answer;
	int max = 0, gap=0;
	for (int index = 0; index < 11; index++)
	{
		int list[11] = { 0 };
		int size = n;
		int lion = 0, apach = 0;

		for (int i = 0; i < 11; i++)
		{
			if (size <= 0) break;
			if (size < info[i] + 1) continue;
			if (i == index)continue;

			list[i] = info[i] + 1;
			size -= list[i];
		}

		if (size > 0) list[10] = size;

		for (int i=0;i<11;i++)
		{
			if (list[i] > info[i])
				lion += 10 - i;
			
			else if(info[i] >0)
				apach += 10 - i;
		}

		if (max == lion - apach)
		{
			max = lion - apach;
			if (gap == 0)
			{
				gap = lion - apach;
				answer.clear();
				for (auto i : list)
				{
					answer.push_back(i);
				}
			}
			
			else if(gap <lion-apach)
			{
				gap = lion - apach;
				answer.clear();
				for (auto i : list)
				{
					answer.push_back(i);
				}
			}

			else if (gap == lion - apach)
			{
				bool chage = false;
				for (int i = 10; i >= 0; i--)
				{	
					if (list[i] > answer[i])
					{
						chage = true;
						break;
					}
					else if (list[i] < answer[i])
					{
						break;
					}
				}
				
				if (chage)
				{
					answer.clear();
					for (auto i : list)
					{
						answer.push_back(i);
					}
				}
			}
		}

		else if (max < lion - apach)
		{
			max = lion - apach;
			gap = lion - apach;
			answer.clear();
			for (auto i : list)
			{
				answer.push_back(i);
			}
		}

		
		for (auto i : list)
		{
			cout << i << " ";
		}
		cout << "\n";
	}

	if (answer.empty()) answer.push_back(-1);
	cout << "==========================\n";
	for (auto i : answer)
	{
		cout << i << " ";
	}
	return answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution(5,{ 0,0,0,1,1,1,1,1,0,0,0 });


	return 0;
}