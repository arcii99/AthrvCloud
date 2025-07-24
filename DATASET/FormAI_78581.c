//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: visionary
#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c, i;

    if (n == 0)
        printf("Enter a non-zero positive integer to generate Fibonacci sequence\n");

    else if (n == 1)
        printf("Fibonacci sequence: %d\n", a);

    else {
        printf("Fibonacci sequence: %d, %d", a, b);

        for (i = 2; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
            printf(", %d", c);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of terms to generate the fibonacci sequence: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}