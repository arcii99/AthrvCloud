//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include <stdio.h>

int factorial(int n) {
    if (n == 1) {
        // Base case for the recursion
        printf("Reached the base case: returning 1\n");
        return 1;
    } else {
        printf("Calling factorial(%d)\n", n-1);
        int result = n * factorial(n-1);
        printf("Factorial calculation completed for %d: returning %d\n", n, result);
        return result;
    }
}

int main() {
    int num = 5;
    printf("The factorial of %d is: %d\n", num, factorial(num));
    return 0;
}