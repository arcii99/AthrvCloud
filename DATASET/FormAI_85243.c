//FormAI DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>

/* This program takes in a user-input number, and outputs
the first 'n' numbers in the Fibonacci sequence */

int main() {

    int num, i;
    unsigned long long int a = 0, b = 1, c = 0;

    // prompt user for number input
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &num);

    // make sure num is positive
    if (num < 1) {
        printf("Error: input must be a positive integer.\n");
        return 1; // exit program
    }

    // output the first 'num' numbers in the Fibonacci sequence
    printf("Fibonacci sequence of %d numbers:\n", num);
    printf("%llu\n", a); // base case
    if (num > 1) { // continue
        printf("%llu\n", b); 
        for (i = 2; i < num; i++) { 
            c = a + b; // add previous two numbers
            printf("%llu\n", c);
            a = b; // shift numbers
            b = c;
        }
    }

    return 0; // exit program
}