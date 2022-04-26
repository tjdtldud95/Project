#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int* n = new int[5];
	int answer = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> n[i];
	}

	for (int i = 0; i < 5; i++)
	{
		answer += n[i] * n[i];
	}

	cout << answer%10;

	
	return 0;
}