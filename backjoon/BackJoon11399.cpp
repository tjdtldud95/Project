#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int N, count = 0;//N: �� ��ȸ�ǿ� �ĺ� ��
    int* votes;
    int before_vote;

    scanf("%d", &N);

    votes = new int[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &votes[i]);//�Է¹����鼭 ��ȣ1������ ������    
    }

    before_vote = votes[0];
    int i = 1;//votes[0]�� ������ ��ȣ1��
    while (i < N)
    {
        if (votes[0] <= votes[i] && votes[i] >= 1)
        {
            votes[0]++;
            votes[i]--;
        }
        else
            count++;//��ȣ1���� �̱� �����

        if (count >= N - 1) break;
        if (i == N - 1 && count < N - 1)
        {
            count = 0;
            i = 0;
        }

        i++;
    }

    printf("%d", votes[0] - before_vote);

    return 0;
}