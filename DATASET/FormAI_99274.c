//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: light-weight
#include <stdio.h>

int main()
{
    int n, first = 0, second = 1, next, i;

    printf("Enter the number of terms:\n");
    scanf("%d", &n);

    printf("Fibonacci Series:\n");

    for (i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }

    return 0;
}