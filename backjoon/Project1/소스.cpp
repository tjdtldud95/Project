#include <iostream>
#include <vector>
using namespace std;

int dp[21][21][21];
int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	else if (a > 20 || b > 20 || c > 20)
	{
		return dp[20][20][20];
	}

	else if (a < b && b < c)
	{
		return dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];

	}

	else
		return dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			for (int r = 0; r < 21; r++)
			{
				dp[i][j][r] = w(i, j, r);
			}
		}
	}
	int a=0, b=0, c=0;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}

		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}


	return 0;
}