//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>

// Function to calculate the Fibonacci sequence
int fibonacci(int num) {
    if (num == 0 || num == 1) {
        return num;
    } else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int main() {
    int n;

    printf("How many numbers in the Fibonacci Sequence would you like to see? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d, ", fibonacci(i));
    }

    printf("\n");

    return 0;
}