//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    int num1 = rand() % 100; // generate a random integer between 0 and 99
    int num2 = rand() % 11; // generate a random integer between 0 and 10
    int addition = num1 + num2;
    int subtraction= num1 - num2;
    double division= (double)num1/num2;
    int multiplication= num1*num2;
    double square_root= sqrt(num1);
    int absolute_value= abs(subtraction);

    printf("The two random numbers are: %d and %d\n", num1, num2);
    printf("%d + %d = %d\n", num1, num2, addition);
    printf("%d - %d = %d\n", num1, num2, subtraction);
    printf("%d * %d = %d\n", num1, num2, multiplication);
    printf("%d / %d = %.2f\n", num1, num2, division);
    printf("The square root of %d is %.2f\n", num1, square_root);
    printf("The absolute value of %d - %d is %d\n", num1, num2, absolute_value);

    return 0;
}