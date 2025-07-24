//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
/*
 * This is a program that calculates the factorial of a number using recursion.
 * Written by [Your Name]
 */

#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        printf("You cannot calculate the factorial of zero.\n");
        return 1;
    } else if (n < 0) {
        printf("You cannot calculate the factorial of a negative number.\n");
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("The factorial of %d is %d.\n", num, factorial(num));
    return 0;
}