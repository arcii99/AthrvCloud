//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: brave
#include <stdio.h>

// Function to generate Fibonacci sequence up to n terms and print it in a visual format
void printFibonacci(int n) {
    int a = 0, b = 1, c;
    printf("%d %d ", a, b); // Print the first two terms

    for (int i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;

        // Print the current term in a visual format
        for (int j = 0; j < c; j++) {
            if (j % 2 == 0) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf(" (%d)\n", c);
    }
}

int main() {
    int n;
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    printFibonacci(n);

    return 0;
}