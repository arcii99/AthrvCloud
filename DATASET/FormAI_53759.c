//FormAI DATASET v1.0 Category: Recursive ; Style: scientific
/* 
This program calculates the factorial of a number using recursive function.
The function recursively calls itself to calculate the factorial of a number.
The user enters a positive integer number and the program will display the factorial.
*/

#include <stdio.h>

int factorial(int n);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Invalid input. Please enter a positive integer.");
    } else {
        printf("Factorial of %d is %d\n", num, factorial(num));
    }
    return 0;
}

// Function to calculate factorial recursively
int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}