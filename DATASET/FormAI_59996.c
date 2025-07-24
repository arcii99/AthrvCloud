//FormAI DATASET v1.0 Category: Recursive ; Style: configurable
#include <stdio.h>

// Recursive function to calculate factorial of a number
int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    printf("Factorial of %d is %d", num, factorial(num));

    return 0;
}