//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int num);

int main()
{
    int num;

    printf("Enter the number of terms to generate: ");
    scanf("%d", &num);

    printf("Fibonacci sequence: ");
    for(int i = 0; i < num; i++)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
}

int fibonacci(int num)
{
    if(num < 2)
    {
        return num;
    }
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}