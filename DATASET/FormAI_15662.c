//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, i;

    printf("Enter the number of terms in the fibonacci sequence: ");
    scanf("%d", &n);

    printf("The first %d terms in the fibonacci sequence are:\n", n);
    for (i=0; i<n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}