//FormAI DATASET v1.0 Category: Scientific ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, n;
    float sum=0, mean, variance, std_deviation;

    printf("Enter the values of n: ");
    scanf("%d", &n);

    float x[n];

    printf("Enter %d real numbers: \n",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
        sum += x[i];
    }

    mean = sum/n;

    for(i=0;i<n;i++)
    {
        variance += pow(x[i]-mean,2);
    }

    variance = variance/n;
    std_deviation = sqrt(variance);

    printf("Mean = %.2f\n", mean);
    printf("Variance = %.2f\n", variance);
    printf("Standard Deviation = %.2f\n", std_deviation);

    return 0;
}