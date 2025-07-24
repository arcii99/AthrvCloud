//FormAI DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include<stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n, result;
    printf("Enter the nth number in the Fibonacci series: ");
    scanf("%d", &n);
    result = fibonacci(n);
    printf("The %dth number in the Fibonacci series is %d", n, result);
    return 0;
}