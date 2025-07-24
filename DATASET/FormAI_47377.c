//FormAI DATASET v1.0 Category: Arithmetic ; Style: multivariable
// This program computes the average and variance of three variables using algebraic formulas
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    printf("Enter three numbers: ");
    scanf("%f %f %f", &a, &b, &c);
    
    float avg = (a + b + c) / 3; // Calculating the average
    float variance = ((a - avg) * (a - avg) + (b - avg) * (b - avg) + (c - avg) * (c - avg)) / 3; // Calculating the variance
    
    printf("The average of the three numbers is: %f\n", avg);
    printf("The variance of the three numbers is: %f\n", variance);
    
    return 0;
}