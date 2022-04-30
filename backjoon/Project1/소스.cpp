#include <iostream>
#include <vector>
using namespace std;

int dp[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> list;
	for (int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		list.push_back(tmp);

		if (i ==0)
		{
			dp[i] += tmp;
		}

		if (i == 1)
		{
			dp[i] += tmp + dp[0];
		}

		if (i == 2)
		{
			dp[2] = max(list[0], list[1]) + list[2];
			dp[2] = max(dp[2], dp[1]);
			continue;
		}
		if (i > 2)
		{
			dp[i] = max(dp[i - 2] + list[i], dp[i - 3] + list[i - 1] + list[i]);
			dp[i] = max(dp[i], dp[i - 1]);
		}
	}
	


	cout << dp[n-1];
	return 0;
}