#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string list;
	int n, pLen,len,answer = 0;

	cin >> n >> len >> list;
	
	
	for (int i=0;i<len;i++)
	{
		int k = 0;
		if (list[i] != 'I') continue;

		while (list[i + 1] == 'O' && list[i + 2] == 'I')
		{
			k++;
			if (k == n)
			{
				answer++;
				k--;
			}
			i += 2;
		}

	}

	cout << answer;
	
	return 0;
}