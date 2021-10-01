#include<iostream>

using namespace std;
int main()
{
	int i, j, num, n, s, r, arr[10] = { 0 };

	cin >> n>>s>>r;

	for (i = 0;i < s;i++)
	{
		cin >> num;
		arr[num-1]= -1;
	}

	for (i = 0;i < r;i++)
	{
		cin >> num;
		arr[num - 1]++;
	}

	for (i = 1;i < n-1;i++)
	{
		if (arr[i - 1] == 1)
		{
			arr[i] ++;
			arr[i - 1] --;
		}
		if (arr[i + 1] == 1)
		{
			arr[i]++;
			arr[i + 1]--;
		}
	}

	cout << j;

	return 0;
}