#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//select sort
	int i, j, tmp, n, arr[1000];

	scanf("%d", &n);

	for (i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0;i < n;i++)
	{
		for (j = i;j < n;j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (i = 0;i < n;i++)
	{
		printf("%d\n", arr[i]);
	}
	//bubble sort
	int i, j, tmp, n, arr[1000];

	scanf("%d", &n);

	for (i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n - 1;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (i = 0;i < n;i++)
	{
		printf("%d\n", arr[i]);
	}



    //input sort 
	int i, j, tmp, n, arr[1000];

	scanf("%d", &n);

	for (i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0;i < n-1;i++)
	{
		j = i;
		while (j >= 0 && arr[j] > arr[j + 1])
		{
			tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
			j--;
		}
	}

	for (i = 0;i < n;i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}