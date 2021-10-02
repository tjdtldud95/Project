#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, i, j, second_min = 0, num = 0,* arr,tmp=0;
	float sum = 0;
	cin >> n;

	arr = (int*)malloc(sizeof(int) * n);


	for (i=0;i < n;i++)
	{
		cin >> arr[i];
		sum += (float)arr[i];
		for (j = 0;j < n;j++)
		{
			if (i == j)continue;

			if (arr[i] == arr[j])
			{
				tmp++;
			}
		}
	}

	sort(arr, arr + n);
	

	printf("\n%.0f\n", sum / n);
	printf("%d\n", arr[n / 2]);
	printf("");
	printf("%d", arr[n - 1] - arr[0]);

	return 0;

}