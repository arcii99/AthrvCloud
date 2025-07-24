//FormAI DATASET v1.0 Category: Random ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, sum = 0, count = 0;
    float mean, variance, standard_deviation;

    printf("Enter the size of array n: ");
    scanf("%d", &n);

    int arr[n];

    //random number generator using time as seed
    srand(time(0));

    //generate numbers and add to array
    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
        sum += arr[i];
        count++;
    }

    mean = (float)sum / n;

    //calculate variance
    for(i = 0; i < n; i++)
    {
        variance += (arr[i] - mean) * (arr[i] - mean);
    }

    variance = variance / (float)n;

    standard_deviation = sqrt(variance);

    printf("The random numbers generated are: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The mean of the array is: %.2f\n", mean);
    printf("The variance of the array is: %.2f\n", variance);
    printf("The standard deviation of the array is: %.2f\n", standard_deviation);

    return 0;
}