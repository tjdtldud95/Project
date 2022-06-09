#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(string s)
{
	int answer = -1;
	vector<char> list;
	
	for (auto i : s)
	{
		if (list.empty())
		{
			list.push_back(i);
			continue;
		}

		if (list.back() == i)
		{
			list.pop_back();
			continue;
		}
		list.push_back(i);
	}

	list.empty() ? answer = 1 : answer = 0;

	return answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//string tmp; cin >> tmp;

	cout<<solution("cdccd");


	return 0;
}