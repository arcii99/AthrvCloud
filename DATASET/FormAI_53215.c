//FormAI DATASET v1.0 Category: Digital signal processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, n;
    float mean, stddev, sum = 0, sumsq = 0;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));

    printf("Enter the integers separated by a space: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
        sumsq += (float)arr[i] * (float)arr[i];
    }

    mean = sum / n;
    stddev = sqrt((sumsq - (float)n * mean * mean) / (float)(n - 1));

    printf("Mean: %f\n", mean);
    printf("Standard Deviation: %f\n", stddev);

    free(arr);
    return 0;
}