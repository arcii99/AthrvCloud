//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void print_sequence(int n);

int main()
{
    int n;

    printf("Enter the number of terms to be printed: ");
    scanf("%d", &n);

    if(n < 0)
    {
        printf("Invalid input.\n");
        return 0;
    }

    printf("\nThe Fibonacci sequence up to %d terms:\n", n);
    print_sequence(n);

    return 0;
}

void print_sequence(int n)
{
    int a = 0, b = 1, c;

    printf("%d ", a);
    if(n == 1) return;

    printf("%d ", b);
    if(n == 2) return;

    for(int i = 3; i<=n; i++)
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}