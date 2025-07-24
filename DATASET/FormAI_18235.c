//FormAI DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>

int main() {
    int n = 10;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    if(n <= 0) {
        printf("Invalid value for n. Please enter a positive integer.");
        return 0;
    }
    int result = fibonacci(n);
    printf("The fibonacci sequence at position %d is %d", n, result);
    return 0;
}

int fibonacci(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}