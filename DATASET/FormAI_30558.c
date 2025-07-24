//FormAI DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 1;
    } else {
        printf("Factorial of %d is %d.\n", num, factorial(num));
        return 0;
    }
}