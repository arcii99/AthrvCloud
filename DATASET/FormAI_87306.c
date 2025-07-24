//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

int fibonacci(int n) {

    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int n, result;

    printf("Enter n: ");
    scanf("%d", &n);

    result = fibonacci(n);

    printf("The %dth number in the Fibonacci series is %d.\n", n, result);

    return 0;
}