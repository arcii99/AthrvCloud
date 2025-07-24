//FormAI DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>

// Function to calculate the factorial of a number using recursion
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int fact = factorial(num);
    printf("Factorial of %d is %d", num, fact);
    return 0;
}