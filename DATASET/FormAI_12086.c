//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms in Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\n\nCalculating Fibonacci Sequence...\n\n");
    usleep(1000 * 2000);

    for (i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        usleep(1000 * 500);
    }

    printf("\n\nFibonacci Sequence Complete.\n\n");

    return 0;
}