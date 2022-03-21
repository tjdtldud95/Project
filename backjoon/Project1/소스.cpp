#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int num1 = 0, num0 = 0;
int answer[1000];

int fibonacci(int n)
{
    if (n == 0) {
        num0++;
        return 0;
    }
    else if (n == 1) {
        num1++;
        return 1;
    }

    if (answer[n] != 0)
        return answer[n];

    else
    {
        answer[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return answer[n];
    }
}
int main()
{
    int n, a;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        fibonacci(a);

        cout << num0 << " " << num1;
        num0 = 0;
        num1 = 0;
    }
    return 0;
}


