//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    printf("Fibonacci Sequence Visualizer\n");

    int limit, i;
    printf("Enter the maximum limit of the sequence: ");
    scanf("%d", &limit);

    int fib[limit];
    fib[0] = 0;
    fib[1] = 1;

    for(i = 2; i < limit; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for(i = 0; i < limit; i++) {
        int j;
        for(j = 0; j < fib[i]; j++) {
            printf(" * ");
        }
        printf("\n");
    }

    return 0;
}