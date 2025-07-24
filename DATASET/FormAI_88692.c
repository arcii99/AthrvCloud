//FormAI DATASET v1.0 Category: Recursive ; Style: careful
#include <stdio.h>

int fibonacci(int n);

int main() {
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    printf("Fibonacci sequence of %d:\n", number);
    for (int i = 0; i < number; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}