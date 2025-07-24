//FormAI DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long fibonacci(int n);

int main()
{
    int num, i;
    long result;
    clock_t start, end;
    double time_used;

    printf("Please enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &num);

    start = clock(); // start the timer

    for (i = 1; i <= num; i++)
    {
        result = fibonacci(i);
        printf("Fibonacci(%d) = %ld\n", i, result);
    }

    end = clock(); // end the timer
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The program took %f seconds to run.\n", time_used);

    return 0;
}

long fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}