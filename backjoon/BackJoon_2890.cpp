#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main()
{
	int i, j, R, C, move[9], rank[9], max = 0;
	char kayak[10][50];

	scanf("%d %d", &R, &C);

	for (i = 0;i < R;i++)
	{
		scanf("%s", kayak[i]);
		for (j = 1;j < C - 1;j++)
		{
			if (kayak[i][j] != '.')
			{
				move[kayak[i][j] - 49] = j - 1;
				break;
			}
		}
	}
	for (i = 0;i < 9;i++)
	{
		if (max < move[i])
			max = move[i];
	}
	j = 1;
	while (max >= 0)
	{
		bool ranked = false;
		for (i = 0;i < 9;i++)
		{
			if (move[i] == max)
			{
				rank[i] = j;
				ranked = true;
			}
		}

		if (ranked)
			j++;

		max--;
	}

	for (i = 0;i < 9;i++)
	{
		printf("%d\n", rank[i]);
	}

	return 0;
}