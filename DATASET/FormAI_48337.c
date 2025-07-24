//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seeding the random number generator with current time

    int num1 = rand() % 100; // generating a random number between 0 and 99
    int num2 = rand() % 100;
    int result;

    printf("Welcome to the energizing arithmetic program!\n");
    printf("I will generate two random numbers between 0 and 99 for you.\n");

    printf("The first number is: %d\n", num1);
    printf("The second number is: %d\n", num2);

    // addition
    result = num1 + num2;
    printf("The sum of these numbers is: %d\n", result);

    // subtraction
    result = num1 - num2;
    printf("The difference of these numbers is: %d\n", result);

    // multiplication
    result = num1 * num2;
    printf("The product of these numbers is: %d\n", result);

    // division
    if (num2 == 0) {
        printf("Oops! The second number is zero, cannot divide.\n");
    } else {
        float quotient = (float) num1 / num2;
        printf("The quotient of these numbers is: %.2f\n", quotient);
    }

    // modulus
    if (num2 == 0) {
        printf("Oops! The second number is zero, cannot perform modulus.\n");
    } else {
        result = num1 % num2;
        printf("The modulus of these numbers is: %d\n", result);
    }

    printf("Thank you for using this energizing arithmetic program!\n");

    return 0;
}