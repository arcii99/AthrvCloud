//FormAI DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num, i;
    float result;
    srand(time(NULL));
    
    // Generate random number between 1 and 100
    num = rand() % 100 + 1;
    
    printf("The randomly generated number is: %d\n", num);
    
    // Calculate the square root of the number
    result = sqrt(num);
    printf("The square root of %d is: %f\n", num, result);
    
    // Calculate the cube of the number
    result = pow(num, 3);
    printf("The cube of %d is: %f\n", num, result);
    
    // Calculate the factorial of the number
    result = 1;
    for (i = 1; i <= num; i++) {
        result *= i;
    }
    printf("The factorial of %d is: %f\n", num, result);
    
    // Calculate the absolute value of the number
    result = abs(num);
    printf("The absolute value of %d is: %f\n", num, result);
    
    return 0;
}