#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include<algorithm>

using namespace std;

struct name
{
public:
	char arr[52];

};

name arr[20000];

bool compare(name name1, name name2)
{
	int len, len2;
	len = strlen(name1.arr);
	len2 = strlen(name2.arr);

	if (len == len2)
	{
		return strcmp(name1.arr, name2.arr) < 0;
	}

	return len < len2;
}

int main()
{
	int n, i, j;

	scanf("%d", &n);


	for (i = 0;i < n;i++)
	{
		scanf("%s", &arr[i].arr);
	}

	sort(arr, arr + n, compare);

	for (i = 0;i < n;i++)
	{
		if (i > 0 && strcmp(arr[i - 1].arr, arr[i].arr) == 0) continue;

		printf("%s\n", arr[i].arr);
	}

	return 0;

}
