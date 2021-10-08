#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, i, j, * arr, min = -5000, tmp, minsize = 0;
	double sum = 0;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
		sum += (double)arr[i];
	}

	sort(arr, arr + n);

	for (i = 0;i < n;i++)
	{
		j = n - 1;
		while (j > i && j > 0)
		{
			if (arr[i] == arr[j])
			{
				tmp = j + 1 - i;
				i = j;
				if (minsize < tmp)
					minsize = tmp;

				break;
			}
			j--;
		}
	}


	if (n < 2)
		min = arr[0];

	else if (minsize == 0)
		min = arr[1];

	else
	{
		for (i = 0;i < 2;i++)
		{
			j = 0;
			while (j + minsize - 1 < n)
			{
				if (arr[j] == arr[j + minsize - 1] && arr[j] > min)
				{
					min = arr[j];
					break;
				}
				j++;
			}
		}
	}


	printf("%.0lf\n", sum / n);
	printf("%d\n", arr[(n - 1) / 2]);
	printf("%d\n", min);
	printf("%d", arr[n - 1] - arr[0]);

	return 0;

}
