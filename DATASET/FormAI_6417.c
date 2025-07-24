//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int scores[] = {88, 92, 78, 90, 84};
    int n = sizeof(scores) / sizeof(scores[0]);
    int max = scores[0];
    int min = scores[0];
    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] > max)
        {
            max = scores[i];
        }
        if (scores[i] < min)
        {
            min = scores[i];
        }
        sum += scores[i];
    }

    float avg = sum / n;

    printf("Maximum score: %d\n", max);
    printf("Minimum score: %d\n", min);
    printf("Average score: %.2f\n", avg);

    return 0;
}