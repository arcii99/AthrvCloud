//FormAI DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include<stdio.h>

int factorial(int n);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d", n, factorial(n));
    return 0;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}