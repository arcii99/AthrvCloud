//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>

// The fibonacci function that generates the sequence up to the limit
long long fibonacci(long long limit) {
    long long num1 = 0, num2 = 1, next = 0;
    printf("%lld %lld ", num1, num2);

    while(next <= limit) {
        next = num1 + num2;
        if(next <= limit) {
            printf("%lld ", next);
        } 
        num1 = num2;
        num2 = next;
    }
    return next;
}

int main(void) {
    long long limit;

    printf("Enter the limit for the Fibonacci sequence: ");
    scanf("%lld", &limit);

    fibonacci(limit);

    return 0;
}