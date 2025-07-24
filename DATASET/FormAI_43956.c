//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>

int main() {
    int n, i;
    long long int first = 0, second = 1, next;
    printf("Enter the number of terms for Fibonacci series:\n");
    scanf("%d", &n);
    printf("%lld %lld ", first, second);
    for (i = 3; i <= n; i++) {
        next = first + second;
        printf("%lld ", next);
        first = second;
        second = next;
    }
    return 0;
}