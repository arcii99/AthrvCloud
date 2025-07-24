//FormAI DATASET v1.0 Category: Recursive ; Style: immersive
#include <stdio.h>

int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n, result;
    printf("Enter a number: ");
    scanf("%d", &n);
    result = factorial(n);
    printf("The factorial of %d is %d\n", n, result);
    return 0;
}