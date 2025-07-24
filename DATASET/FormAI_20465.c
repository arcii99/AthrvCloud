//FormAI DATASET v1.0 Category: Random ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // set seed for random number generation

    int num1, num2, num3;

    // generate random numbers between 1 and 10
    num1 = rand() % 10 + 1; 
    num2 = rand() % 10 + 1;
    num3 = rand() % 10 + 1;

    // print the randomly generated numbers
    printf("Random Numbers: %d, %d, %d\n", num1, num2, num3);

    // generate a random operator
    int operator = rand() % 4; // 0 = addition, 1 = subtraction, 2 = multiplication, 3 = division

    // perform the operation based on the random operator
    int result;
    switch(operator) {
        case 0: // addition
            result = num1 + num2 + num3;
            printf("Addition: %d + %d + %d = %d\n", num1, num2, num3, result);
            break;
        case 1: // subtraction
            result = num1 - num2 - num3;
            printf("Subtraction: %d - %d - %d = %d\n", num1, num2, num3, result);
            break;
        case 2: // multiplication
            result = num1 * num2 * num3;
            printf("Multiplication: %d * %d * %d = %d\n", num1, num2, num3, result);
            break;
        case 3: // division
            result = num1 / num2 / num3;
            printf("Division: %d / %d / %d = %d\n", num1, num2, num3, result);
            break;
    }

    return 0;
}