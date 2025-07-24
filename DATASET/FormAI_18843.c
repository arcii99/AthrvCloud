//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>

// Function to print the Fibonacci sequence
void printFibonacci(int n)
{
    int a = 0, b = 1, c, i;
    printf("%d %d ", a, b); // print first two terms

    for(i=3; i<=n; i++)
    {
        c = a + b; // next term is sum of previous two terms
        printf("%d ", c);
        a = b;
        b = c;
    }
}

// Visualize the Fibonacci sequence
void visualizeFibonacci(int n)
{
    int a = 0, b = 1, c, i, j, k = 0;
    char colors[7][10] = {
        {"\033[0;31m"}, // red
        {"\033[0;32m"}, // green
        {"\033[0;33m"}, // yellow
        {"\033[0;34m"}, // blue
        {"\033[0;35m"}, // purple
        {"\033[0;36m"}, // cyan
        {"\033[0;37m"}  // white
    };

    for(i=1; i<=n; i++)
    {
        c = a + b; // next term is sum of previous two terms
        a = b;
        b = c;

        for(j=1; j<=c; j++)
        {
            if(k >= 7) k = 0; // repeat color sequence if end is reached
            printf("%s*", colors[k]);
            k++;
        }
        printf("\033[0m\n"); // reset color to default
    }
}

int main()
{
    int n = 10;
    printf("Fibonacci sequence up to %d terms:\n", n);
    printFibonacci(n);

    printf("\n\nVisualizing Fibonacci sequence up to %d:\n", n);
    visualizeFibonacci(n);

    return 0;
}