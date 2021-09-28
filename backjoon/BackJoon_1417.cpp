#include <iostream>

int main()
{
    int i, num, k = 0, max = 0, max_index, vote[1000];

    scanf_s("%d", &num);

    for (i = 0;i < num;i++)
    {
        scanf_s("%d", &vote[i]);
    }

    while (1)
    {
        max = -1;
        max_index = 0;
        for (i = 1;i < num;i++)
        {
            if (max <= vote[i])
            {
                max = vote[i];
                max_index = i;
            }
        }

        if (vote[0] > max)
            break;

        vote[0]++;
        vote[max_index]--;
        k++;
    }

    printf("%d\n", k);
    return 0;
}
