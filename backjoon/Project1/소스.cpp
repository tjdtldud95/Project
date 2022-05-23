#include <vector>
#include <iostream>
#include <map>
using namespace std;

bool isPoll[101];
void check(const vector<int> list[], const int& start = 1)
{
	for (int it : list[start])
	{
		if (isPoll[it])	continue;
		isPoll[it] = true;
		check(list, it);
	}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> list[101];
	int n, m, answer = 0;

	int con1, con2;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> con1 >> con2;

		list[con1].push_back(con2);
		list[con2].push_back(con1);
	}
	check(list);

	
	for (int i = 2; i <= n; i++)
	{
		if (isPoll[i])// answer++;
		{
			cout << i << " ";
			answer++;
		}
	}

	cout <<"\n" << answer;

	return 0;
}