//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));  // seed for random number generator
    int num1 = rand() % 100;  // generating first random number between 0 to 99
    int num2 = rand() % 50;  // generating second random number between 0 to 49

    float result1 = sqrt(num1);  // calculate the square root of num1
    float result2 = pow(num2, 2);  // calculate the power of num2 to 2

    printf("The first random number is: %d\n", num1);
    printf("The second random number is: %d\n", num2);
    printf("The square root of the first number is: %.2f\n", result1);
    printf("The second number raised to the power of 2 is: %.2f\n", result2);

    // find the maximum and minimum of the two results
    float max = (result1 > result2) ? result1 : result2;
    float min = (result1 < result2) ? result1 : result2;

    // generate another random number between 0 to the maximum value rounded up
    int num3 = rand() % (int) ceil(max);
    
    // find the absolute difference between num3 and the minimum value
    float diff = fabs(num3 - min);

    printf("The maximum value between the two results is: %.2f\n", max);
    printf("The minimum value between the two results is: %.2f\n", min);
    printf("The random number generated between 0 and the max value is: %d\n", num3);
    printf("The absolute difference between the random number and the minimum value is: %.2f\n", diff);

    return 0;  // exit program
}