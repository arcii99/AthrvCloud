//FormAI DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>

int recursiveSum(int n);

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Invalid input!\n");
    } else {
        printf("Sum of %d natural numbers: %d\n", n, recursiveSum(n));
    }
    return 0;
}

int recursiveSum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return (n + recursiveSum(n-1));
    }
}