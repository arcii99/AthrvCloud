//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>

int fibonacci(int num);

int main()
{
    int num, i = 0, c;
    printf("Enter the number of terms you want to generate in the Fibonacci sequence:\n");
    scanf("%d", &num);
    printf("Fibonacci sequence:\n");
    for (c = 0; c < num; c++)
    {
        printf("%d ", fibonacci(i));
        i++;
    }
    printf("\n");
    return 0;
}

int fibonacci(int num)
{
    if (num == 0 || num == 1)
    {
        return num;
    }
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}