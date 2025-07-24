//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>

int main()
{
    int n, i, c = 0;
    printf("Enter the number of terms in Fibonacci sequence: ");
    scanf("%d", &n);

    int f1 = 0, f2 = 1, f3;

    printf("Fibonacci Sequence:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", f1);
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    printf("\n\nFibonacci Pattern:\n");

    for (i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", c);
            c = !c;
        }
        printf("\n");
    }

    return 0;
}