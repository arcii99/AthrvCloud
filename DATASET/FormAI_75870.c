//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: recursive
#include <stdio.h>

void fibonacci(int n)
{
    static int first = 0, second = 1, next;
    if(n > 0)
    {
        next = first + second;
        first = second;
        second = next;
        printf("%d ", next);
        fibonacci(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter the number of terms of Fibonacci Series you want to see:\n");
    scanf("%d", &n);
    if(n == 1)
    {
        printf("0\n");
    }
    else if(n == 2)
    {
        printf("0 1\n");
    }
    else
    {
        printf("0 1 ");
        fibonacci(n - 2);
    }
    return 0;
}