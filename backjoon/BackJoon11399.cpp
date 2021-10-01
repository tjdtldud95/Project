#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int N, count = 0;//N: 총 국회의원 후보 수
    int* votes;
    int before_vote;

    scanf("%d", &N);

    votes = new int[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &votes[i]);//입력받으면서 기호1번보다 많으면    
    }

    before_vote = votes[0];
    int i = 1;//votes[0]은 언제나 기호1번
    while (i < N)
    {
        if (votes[0] <= votes[i] && votes[i] >= 1)
        {
            votes[0]++;
            votes[i]--;
        }
        else
            count++;//기호1번이 이긴 사람수

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