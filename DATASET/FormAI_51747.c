//FormAI DATASET v1.0 Category: Recursive ; Style: lively
#include<stdio.h>

int factorial(int n) {
    // If the number is 0 or 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // recursively calculate the factorial of the number
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    // If the number is negative, we cannot calculate its factorial
    if (num < 0) {
        printf("Invalid input. Please enter a positive number.\n");
    }
    else {
        int fact = factorial(num);
        printf("The factorial of %d is: %d\n", num, fact);
    }
    return 0;
}