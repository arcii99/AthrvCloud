//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 50

void clear()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();

    while (goal > clock());
}

void printFibonacci(int n)
{
    int i, j = 0, k = 1;

    for (i = 1; i <= n; i++)
    {
        printf("%d, ", k);
        delay(50);

        int temp = j + k;
        j = k;
        k = temp;

        if (i % 8 == 0)
        {
            clear();
        }
    }

    printf("\n\nPress enter to exit...");
    getchar();
}

int main()
{
    int n;

    printf("Enter the number of terms to generate in the Fibonacci sequence (1-%d):\n", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid input. Please enter a value between 1 and %d.", MAX);
        return 1;
    }

    printf("\nGenerating Fibonacci sequence...\n\n");

    printFibonacci(n);

    return 0;
}