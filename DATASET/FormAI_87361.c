//FormAI DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>

int recursiveSum(int n);

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("The sum of numbers from 1 to %d is %d\n", n, recursiveSum(n));
    return 0;
}

int recursiveSum(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + recursiveSum(n-1);
    }
}