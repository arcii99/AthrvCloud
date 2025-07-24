//FormAI DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

int main()
{
    int i, n, sum = 0, count = 0;
    float mean, std_dev, variance = 0;
    int arr[SIZE];

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    mean = (float)sum/n;

    for(i = 0; i < n; i++)
    {
        variance += pow(arr[i] - mean, 2);
        count++;
    }

    variance /= count;
    std_dev = sqrt(variance);

    printf("\nStatistics of Array\n");
    printf("---------------------------\n");
    printf("Number of Elements: %d\n", n);
    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", variance);
    printf("Standard Deviation: %f\n", std_dev);

    return 0;
}