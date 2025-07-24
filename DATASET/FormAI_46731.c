//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c;
    printf("%d %d ", a, b); // Print the first two numbers of the sequence
    
    for (int i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);

        a = b;
        b = c;
    }
}

int main() {
    int n;
    printf("Please enter the number of terms to print: ");
    scanf("%d", &n);
    
    printf("Fibonacci sequence: ");
    fibonacci(n);
    
    return 0;
}