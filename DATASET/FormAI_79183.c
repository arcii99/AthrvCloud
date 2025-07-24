//FormAI DATASET v1.0 Category: Calculator ; Style: statistical
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int a, b, c;
    float mean=0.0, variance=0.0, stddev=0.0;
    
    printf("Enter three numbers: ");
    scanf("%d%d%d", &a, &b, &c); // Taking user input
    
    mean = (a + b + c) / 3.0; //calculating mean
    
    variance = ((a-mean)*(a-mean) + (b-mean)*(b-mean) + (c-mean)*(c-mean)) / 3.0; // calculating variance
    
    stddev = sqrt(variance); // calculating standard deviation
    
    printf("\n======================================\n");
    printf("||  Statistical calculator in C      ||\n");
    printf("======================================\n\n");
    
    printf("The entered numbers are: %d, %d, %d\n", a, b, c);
    
    printf("Mean is : %.2f\n", mean);
    printf("Variance is : %.2f\n", variance);
    printf("Standard Deviation is : %.2f\n", stddev);
    
    printf("======================================\n");
    
    return 0;
}