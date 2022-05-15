#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include<algorithm>
using namespace std;


bool list[30][30];
char bach[30][30];

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int index = 0;
	bool again;

	for(auto its : board)
	{
		int len = its.size();
		for (int i = 0; i < len; i++)
		{
			list[index][i] = true;
			bach[index][i] = board[index][i];
		}
		index++;
	}

	do 
	{
		again = false;
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (bach[i][j] == '0' ) continue;

				if (bach[i][j] == bach[i][j + 1]
					&& bach[i + 1][j] == bach[i + 1][j + 1]
					&& bach[i][j] == bach[i + 1][j + 1])
				{
					list[i][j] = false;
					list[i][j + 1] = false;
					list[i + 1][j] = false;
					list[i + 1][j + 1] = false;

					again = true;
				}
			}
		}

		for (int i = 0; i < m ; i++)
		{
			for (int j = 0; j < n ; j++)
			{
				if (list[i][j] == false)
				{
					bach[i][j] = '0';
				}
			}
		}
		
		for (int i = m; i >0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				if (bach[i][j] == '0')
				{
					for (int pos = i - 1; ; pos--)
					{
						if (pos < 0)break;
						if (bach[pos][j] != '0')
						{
							list[i][j] = true;
							list[pos][j] = false;

							bach[i][j] = bach[pos][j];
							bach[pos][j] = '0';
							break;
						}
					}
				}
			}
			
		}
	} while (again);
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (bach[i][j] == '0')
			{
				answer++;
			}
		}
	}


	cout << answer;
	return answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution(7, 2, { "AA", "BB", "AA", "BB", "ZZ", "ZZ", "CC" });

	return 0;
}