//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: all-encompassing
#include <stdio.h>

void fibonacci_visualizer(int n) {
    int fibonacci[n];
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    printf("Fibonacci Sequence:\n");

    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < fibonacci[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &n);

    fibonacci_visualizer(n);
    
    return 0;
}