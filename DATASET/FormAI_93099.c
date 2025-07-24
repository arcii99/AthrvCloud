//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>

int factorial(int n) {
    if (n < 0) {
        printf("Negative numbers are not allowed!\n");
        return -1;
    } else if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("\nCalculating factorial of %d...\n\n", num);

    int result = factorial(num);

    if (result == -1) {
        printf("Error: Negative input\n");
    } else {
        printf("Factorial of %d is %d\n", num, result);
    }

    return 0;
}