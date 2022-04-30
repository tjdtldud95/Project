#include <iostream>
using namespace std;


int list[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp, n, r,k=0,sum=0; cin >> n >> r;
	int answer = INT16_MIN,index = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		list[i] = tmp;
		sum += tmp;
		k++;
		if (k == r)
		{
			if (answer < sum)
			{
				answer = sum;
			}

			sum -= list[index];
			index++;
			k--;
		}

	}

	cout << answer;


	return 0;
}