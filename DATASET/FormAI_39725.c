//FormAI DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int factorial(int n) {
    if (n == 1) {
        return n;
    }
    return n * factorial(n-1);
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Fibonacci series up to %d terms: ", num);
    for (int i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\nFactorial of %d: %d", num, factorial(num));

    return 0;
}