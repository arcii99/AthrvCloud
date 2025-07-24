//FormAI DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int a = 5, b = 6, c;
    printf("Enter value for c: ");
    scanf("%d", &c);

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b); // use %% to print % symbol
    printf("c + 5 = %d\n", c + 5);
    printf("c - 5 = %d\n", c - 5);
    printf("c * 5 = %d\n", c * 5);
    printf("c / 5 = %d\n", c / 5);
    printf("c %% 5 = %d\n", c % 5);

    int n = 10; // Calculate the first 10 fibonacci numbers
    for (int i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");

    return 0;
}