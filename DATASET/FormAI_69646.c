//FormAI DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN 1
#define MAX 10

int main() {
    srand(time(NULL));  // seed for random number generator
    int num1 = rand() % (MAX - MIN + 1) + MIN;  // generate random number between MIN and MAX
    int num2 = rand() % (MAX - MIN + 1) + MIN;  // generate another random number
    int result = 0;
    
    printf("Let's do some arithmetic!\n");
    
    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    
    // multiplication
    result = num1 * num2;
    printf("%d * %d = %d\n", num1, num2, result);
    
    // division
    if (num1 % num2 == 0) {
        result = num1 / num2;
        printf("%d / %d = %d\n", num1, num2, result);
    }
    else {
        printf("Cannot divide %d by %d evenly\n", num1, num2);
    }
    
    // addition
    result = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, result);
    
    // subtraction
    result = num1 - num2;
    printf("%d - %d = %d\n", num1, num2, result);
    
    // modulus
    if (num1 >= num2) {
        result = num1 % num2;
        printf("%d %% %d = %d\n", num1, num2, result);
    }
    else {
        result = num2 % num1;
        printf("%d %% %d = %d\n", num2, num1, result);
    }

    return 0;
}