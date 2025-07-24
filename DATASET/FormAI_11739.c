//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: detailed
#include <stdio.h>

void fibonacci(int n) {
    int i, first = 0, second = 1, next;

    printf("Fibonacci Series: ");
    for(i=0; i<n; i++) {
        if(i<=1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
}

int main() {
    int n;
    printf("Enter the number of elements for Fibonacci Sequence: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}