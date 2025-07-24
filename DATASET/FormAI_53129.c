//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surprised
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    int a = 0, b = 1, c;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d, ", a);
            continue;
        }
        if (i == 2) {
            printf("%d, ", b);
            continue;
        }
        c = a + b;
        a = b;
        b = c;
        printf("%d, ", c);
        if (i % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}