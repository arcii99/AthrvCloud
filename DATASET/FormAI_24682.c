//FormAI DATASET v1.0 Category: Scientific ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, k, n;
    double sum=0, val, deviation, stdev;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    double array[n];

    printf("Enter the %d values of the array: ", n);
    for(i=0;i<n;i++){
        scanf("%lf", &val);
        array[i] = val;
        sum += val;
    }
    double mean = sum / n;

    for(j=0;j<n;j++){
        deviation = array[j] - mean;
        stdev += pow(deviation, 2);
    }
    stdev /= n;

    printf("\nMean: %lf\n", mean);
    printf("Standard Deviation: %lf\n", sqrt(stdev));

    return 0;
}