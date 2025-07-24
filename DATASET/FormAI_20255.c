//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Alan Touring
#include <stdio.h>

unsigned int factorial(unsigned int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    unsigned int n;
    printf("Enter a non-negative integer: ");
    scanf("%u", &n);
    printf("%u! = %u\n", n, factorial(n));
    return 0;
}