//FormAI DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>

/* This program calculates the factorial of a given number using recursion */

int factorial(int n) {
    if(n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num < 0)
        printf("Factorial of negative number does not exist.\n");
    else
        printf("Factorial of %d is %d.\n", num, factorial(num));

    return 0;
}