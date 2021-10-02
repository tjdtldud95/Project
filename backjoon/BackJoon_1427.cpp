#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int i, j;
	char num[10],tmp;

	scanf("%s",num);
	
	for (i = 0;num[i] != '\0';i++)
	{
		j = i;
		while(j>=0 && num[j]<num[j+1])
		{
			tmp = num[j+1];
			num[j+1] = num[j];
			num[j] = tmp;
			j--;
		}
	}
	
	printf("%s", num);


	return 0;

}
