//FormAI DATASET v1.0 Category: Recursive ; Style: happy
// Let's write a happy program that computes Fibonacci numbers recursively!
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    printf("Let's compute some Fibonacci numbers!\n");
    int n;
    while (1) {
        printf("Please enter a positive integer (type -1 to quit): ");
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        int result = fibonacci(n);
        printf("The %dth Fibonacci number is: %d\n", n, result);
    }
    printf("Thanks for playing! Have a happy day!\n");
    return 0;
}