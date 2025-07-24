//FormAI DATASET v1.0 Category: Recursive ; Style: Cyberpunk
#include <stdio.h>

int factorial(int n) {
    if (n == 1) { // base case
        return 1;
    } else {
        return n * factorial(n-1); // recursive case
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Error: Input must be positive.\n");
    } else {
        printf("%d! = %d\n", n, factorial(n));
    }
    return 0;
}