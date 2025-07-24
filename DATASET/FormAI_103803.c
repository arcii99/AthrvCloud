//FormAI DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n, i;
    int fib_series[MAX_SIZE];

    printf("Enter the number of terms to generate in the fibonacci series: ");
    scanf("%d", &n);

    // Print the generated fibonacci series using recursion
    for (i = 0; i < n; i++) {
        fib_series[i] = fibonacci(i);
        printf("%d ", fib_series[i]);
    }

    printf("\n");

    // Calculate the sum of the fibonacci series using recursion
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += fibonacci(i);
    }
    printf("The sum of the fibonacci series is: %d\n", sum);

    return 0;
}