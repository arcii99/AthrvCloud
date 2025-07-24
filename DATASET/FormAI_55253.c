//FormAI DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10

int main()
{
    float avg, var, st_dev;
    float arr[MAX], sum=0, sum_squares=0;
    int i, n;

    printf("Enter the number of temperature readings:");
    scanf("%d", &n);
    printf("Enter %d temperature readings:", n);
    
    for (i=0; i<n; i++)
    {
        scanf("%f", &arr[i]);
        sum += arr[i];
        sum_squares += arr[i]*arr[i];
    }

    avg = sum/n;
    var = (sum_squares/n) - (avg*avg);
    st_dev = sqrt(var);

    printf("Mean temperature reading: %.2f\n", avg);
    printf("Temperature variance: %.2f\n", var);
    printf("Temperature standard deviation: %.2f\n", st_dev);

    return 0;
}