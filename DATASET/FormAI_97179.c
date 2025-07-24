//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: automated
#include <stdio.h>

// function to calculate and print the fibonacci sequence
void fibonacci(int n) {
    int prev = 0;
    int curr = 1;

    for (int i = 1; i <= n; i++) {
        printf("%d ", curr);
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
}

int main() {
    int n;
    printf("Enter the number of terms to be generated: ");
    scanf("%d", &n);

    printf("The first %d terms of the Fibonacci sequence are: ", n);

    // call the fibonacci function
    fibonacci(n);

    return 0;
}