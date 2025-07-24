//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Dennis Ritchie
#include<stdio.h>

void fibonacciVisualizer(int n)
{
    int n1 = 0, n2 = 1, n3;

    printf("%d %d ", n1, n2);

    for(int i = 2; i < n; i++)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;

        if(n3 % 3 == 0 && n3 % 5 == 0)
        {
            printf("FIZZBUZZ ");
        }
        else if(n3 % 3 == 0)
        {
            printf("FIZZ ");
        }
        else if(n3 % 5 == 0)
        {
            printf("BUZZ ");
        }
        else
        {
            printf("%d ", n3);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    fibonacciVisualizer(n);
    return 0;
}