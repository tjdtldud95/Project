#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main()
{
	char arr[50][50];
	int i, j, x, y, hap, s_x = 0, s_y = 0, min = 2500;
	int wmin, bmin;

	scanf("%d %d", &x, &y);

	for (i = 0;i < x;i++)
	{
		scanf(" %s", arr[i]);
	}

	while (s_x + 7 < x)
	{
		hap = 0;
		wmin = 0;
		bmin = 0;

		for (i = s_x;i < s_x + 8;i++)
		{
			for (j = s_y;j < s_y + 8;j++)
			{
				if (i % 2 == 0)
				{
					//case W :
					if (j % 2 == 0 && arr[i][j] != 'W')
					{
						wmin++;
					}

					else if (j % 2 != 0 && arr[i][j] != 'B')
					{
						wmin++;
						
					}

					//case B :
					if (j % 2 == 0 && arr[i][j] != 'B')
					{
						bmin++;
					}

					else if (j % 2 != 0 && arr[i][j] != 'W')
					{
						bmin++;
					}
				}

				else
				{
					//case W :
					if (j % 2 == 0 && arr[i][j] != 'B')
					{
						wmin++;
					}

					else if (j % 2 != 0 && arr[i][j] != 'W')
					{
						wmin++;
					}

					//case B :
					else if (j % 2 == 0 && arr[i][j] != 'W')
					{
						bmin++;
					}

					else if (j % 2 != 0 && arr[i][j] != 'B')
					{
						bmin++;
					}
				}
			}
		}
		
		if (wmin > bmin)
			hap = bmin;

		else
			hap = wmin;
		

		if (min > hap)
		{
			min = hap;
		}

		s_y++;
		if (s_y + 7 >= y)
		{
			s_y = 0;
			s_x++;
		}
	}

	printf("%d\n", min);


	return 0;
}