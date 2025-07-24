//FormAI DATASET v1.0 Category: Scientific ; Style: relaxed
#include <stdio.h>

/*
 * This program calculates the factorial of a given number using recursion
 * The user inputs a number and the program calculates its factorial
 */

int factorial(int n) {
    if(n==0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int number, fact;
    printf("Please enter a number: ");
    scanf("%d", &number);
    
    if(number < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }
    else {
        fact = factorial(number);
        printf("%d! = %d\n", number, fact);
        return 0;
    }
}