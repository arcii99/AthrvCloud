//FormAI DATASET v1.0 Category: Math exercise ; Style: modular
/* This program is a C Math exercise example program in a modular style. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Function prototypes */
int generateRandomNumber(int min, int max);
double findSquareRoot(double num);
double findPower(double base, double exponent);

int main() {
    srand(time(NULL)); /* Seed the random number generator */
    int num1 = generateRandomNumber(1, 10); /* Generate a random number between 1 and 10 */
    int num2 = generateRandomNumber(1, 10); /* Generate a second random number between 1 and 10 */
    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);
    double root = findSquareRoot(num1);
    double result = findPower(num1, num2);
    printf("The square root of %d is %.2f\n", num1, root);
    printf("%d raised to the power of %d is %.2f\n", num1, num2, result);
    return 0;
}

/* Function to generate a random number between a minimum and maximum value */
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to find the square root of a number */
double findSquareRoot(double num) {
    return sqrt(num);
}

/* Function to find the power of a base raised to an exponent */
double findPower(double base, double exponent) {
    return pow(base, exponent);
}