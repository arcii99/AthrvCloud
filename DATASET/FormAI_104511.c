//FormAI DATASET v1.0 Category: Arithmetic ; Style: statistical
#include<stdio.h>
#include<math.h>

/* This program calculates statistical values using arithmetic operations */

int main() {

    // Declare variables
    int n, i;
    float x, mean, sum = 0.0, sd = 0.0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements
    printf("Enter the %d elements: ", n);
    for(i=0; i<n; i++) {
        scanf("%f", &x);
        sum += x;
    }
    // Calculate mean
    mean = sum/n;

    // Calculate standard deviation
    for(i=0; i<n; i++) {
        sd += pow(x - mean, 2);
    }
    sd = sqrt(sd/n);

    // Output the results
    printf("Mean = %0.2f\n", mean);
    printf("Standard Deviation = %0.2f\n", sd);

    return 0;
}