//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>

int main() {
    int n, i, a = 0, b = 1, c;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Sequence: ");
    for (i = 1; i <= n; i++) {
        printf("%d, ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}