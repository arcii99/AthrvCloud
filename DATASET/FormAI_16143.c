//FormAI DATASET v1.0 Category: Recursive ; Style: configurable
#include <stdio.h>

// Function to calculate factorial of a number
int factorial(int n) {
    if (n == 0) {
        // base case
        return 1;
    } else {
        // recursive case
        return n * factorial(n-1); // function calls itself
    }
}

int main() {
    // take input from user
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // calculate factorial using recursive function
    int fact = factorial(num);

    // print the factorial
    printf("Factorial of %d is %d.", num, fact);

    return 0;
}