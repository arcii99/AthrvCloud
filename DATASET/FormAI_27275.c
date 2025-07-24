//FormAI DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdio.h>

int fibonacci(int n) {
    if (n < 2) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n, i;

    printf("Enter the number of terms you want in the fibonacci sequence: ");
    scanf("%d", &n);

    printf("The fibonacci sequence of %d terms:\n", n);

    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    return 0;
}