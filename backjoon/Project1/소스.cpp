#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,max = 0;
	double* a;
	double answer=0.f;
	cin >> n;
	a= new double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (max < a[i])
		{
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i]/ max;
		a[i] *= 100;
	}

	for (int i = 0; i < n; i++)
	{
		answer += a[i];
	}

	answer /= n;
	
	printf("%lf", answer);
	
	return 0;
}