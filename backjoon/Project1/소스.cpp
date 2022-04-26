#include <iostream>
#include <vector>
using namespace std;


int bp[100000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,tmp; cin >> n;
	vector<int> list;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		list.push_back(tmp);
	}

	bp[0] = list[0];
	bp[1] = list[0] + list[1];
	bp[2] = max(list[0], list[1]) + list[2];
	for (int i = 3; i < n; i++)
	{
		bp[i] = max(bp[i - 2] + list[i], bp[i - 3] + list[i - 1] + list[i] );
	}

	cout << bp[n - 1];
	return 0;
}