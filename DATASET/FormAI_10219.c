//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Alan Touring
#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int n;

    printf("Please enter a number: ");
    scanf("%d", &n);

    printf("The factorial of %d is %d\n", n, factorial(n));

    return 0;
}