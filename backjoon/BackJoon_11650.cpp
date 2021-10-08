#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

class position
{
public:
	int x, y;

	bool operator < (position& position)
	{
		if (this->x == position.x) return this->y < position.y;

		return this->x < position.x;
	}
};

int main()
{
	int i, j, r, t, n;
	position *arr, tmp;

	scanf("%d", &n);

	arr = (position*)malloc(sizeof(position) * n);

	for (i = 0;i < n;i++)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	sort(arr, arr + n);


	for (i = 0;i < n;i++)
	{
		printf("%d %d\n", arr[i].x, arr[i].y);
	}

	free(arr);
	return 0;

}
