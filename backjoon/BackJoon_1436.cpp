#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>

int main()
{
	int i, n, num = 0;
	char name[100];

	scanf("%d", &n);

	for (i = 0;i < n;i++)
	{
		while (1)
		{
			num++;
			sprintf(name, "%d", num);

			if (strstr(name, "666") != NULL)
			{
				break;
			}

		}
	}
	printf("%d\n", atoi(name));

	return 0;
}