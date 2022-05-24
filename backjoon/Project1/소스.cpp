#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<int>* list = new vector<int>[n + 1];

	int max = n;
	int index = 1, repeat = 0;
	int i, m = 1;
	while (1)
	{
		for (i = 0; i < max; i++)
		{
			if (list[m].size() == 0)
			{
				list[m].push_back(index++);
				m++;
			}
			else
			{
				list[m].insert(list[m].begin() + repeat, index++);
				m++;
			}
		}
		m--;
		max--;
		if (max < 0) break;

		for (i = 0; i < max; i++)
		{
			if (list[m].size() == 0)
				list[m].push_back(index++);

			else
				list[m].insert(list[m].end() - repeat, index++);

		}
		m--;
		max--;
		if (max < 0) break;

		for (i = 0; i < max; i++)
		{
			if (list[m].size() == 0 )
				list[m--].push_back(index++);

			else
			{
				list[m].insert(list[m].end()- repeat, index++);
				m--;
			}
		}
		m += 2;
		max--;
		repeat++;
		if (max < 0) break;
	}

	for (int i = 1; i <= n; i++)
	{
		cout<<i<<"  : ";
		for (auto it : list[i])
		{
			cout << it << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto it : list[i])
		{
			answer.push_back(it);
		}
	}

	for (auto i : answer)
		cout << i << " ";
	return answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	solution(5);

	return 0;
}