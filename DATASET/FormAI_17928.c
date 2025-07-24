//FormAI DATASET v1.0 Category: Scientific ; Style: complex
#include <stdio.h>

// Declare the factorial function recursively
int recursive_factorial(int n) {
    // Base case
    if (n == 0) {
        return 1;
    }
    // Recursive case
    else {
        return n * recursive_factorial(n - 1);
    }
}

// Declare the factorial function iteratively
int iterative_factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Error: Entered number is negative\n");
    }
    else {
        int recursive_result = recursive_factorial(num);
        int iterative_result = iterative_factorial(num);
        printf("The factorial of %d using recursion is %d\n", num, recursive_result);
        printf("The factorial of %d using iteration is %d\n", num, iterative_result);
    }
    return 0;
}