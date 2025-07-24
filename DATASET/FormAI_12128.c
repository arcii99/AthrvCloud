//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>

int fibonacci(int n) {
    int result;

    if (n < 2) {
        result = n;
    } else {
        result = fibonacci(n - 1) + fibonacci(n - 2);
    }

    return result;
}

int main() {
    int i, n;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");

    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}