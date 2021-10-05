#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, i, j, * arr, min;
	double sum = 0;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
		sum += (double)arr[i];
	}

	sort(arr, arr + n);

	if (n < 2)
		min = arr[0];

	else
		min = arr[1];

	for (i = 0, j = 0;i < n - 1;i++)
	{
		if (arr[i] == arr[i + 1])
		{
			min = arr[i];
			j++;
		}
		if (j == 2)
			break;
	}

	printf("%.0lf\n", sum / n);
	printf("%d\n", arr[(n - 1) / 2]);
	printf("%d\n", min);
	printf("%d", arr[n - 1] - arr[0]);

	return 0;

}
