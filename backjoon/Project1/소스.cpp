#include <iostream>

using namespace std;

int blue, white;
int list[130][130];
void cal(int xStart ,int yStart, int max)
{
	int sum = 0;
	for (int i = xStart; i < xStart+max; i++)
	{
		for (int j = yStart; j < yStart+max; j++)
		{
			sum += list[i][j];
		}
	}

	if (sum == max*max)
		blue++;

	else if (sum == 0)
		white++;

	else
	{
		cal(xStart, yStart, max / 2);
		cal(xStart, yStart+max/2, max / 2);
		cal(xStart+max/2, yStart,  max / 2);
		cal(xStart + max / 2, yStart + max / 2, max / 2);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp; cin >> temp;
			list[i][j] = temp;
		}
	}

	cal(0, 0, n);

	cout << white << "\n" << blue;


	return 0;
}