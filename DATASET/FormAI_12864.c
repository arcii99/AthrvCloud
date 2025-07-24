//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random numbers
int generateRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL));  // initialize the random seed

    int num1 = generateRandom(1, 100);  // generate a random number between 1 and 100
    int num2 = generateRandom(1, 100);  // generate another random number between 1 and 100

    printf("The first number is: %d\n", num1);
    printf("The second number is: %d\n", num2);

    // calculate the sum, difference, product, and quotient of num1 and num2
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    float quotient = (float) num1 / num2;

    // output the results
    printf("The sum of the two numbers is: %d\n", sum);
    printf("The difference of the two numbers is: %d\n", difference);
    printf("The product of the two numbers is: %d\n", product);
    printf("The quotient of the two numbers is: %f\n", quotient);

    return 0;
}