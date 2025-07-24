//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

// Recursive Function
int recursive_fibonacci(int n)
{
    if (n < 2)
        return n;
    else
        return (recursive_fibonacci(n-1) + recursive_fibonacci(n-2));
}

void *calc_fibonacci(void *arg)
{
    int n = *((int *)arg);
    int result = recursive_fibonacci(n);
    printf("Fibonacci of %d is: %d\n", n, result);
    pthread_exit(0);
}

int main()
{
    pthread_t threads[MAX];   // array for multiple threads
    int print_values[MAX];    // array to store values to be printed
    int i, j;

    // Generate random numbers between 1-30 and store them in an array
    for(i = 0; i < MAX; i++)
        print_values[i] = rand() % 30 + 1;

    // Create multiple threads to calculate Fibonacci for each value
    for (j = 0; j < MAX; j++)
    {
        int *ptr = &print_values[j];
        pthread_create(&threads[j], NULL, calc_fibonacci, (void *)ptr);
    }

    // Wait for each thread to finish
    for (j = 0; j < MAX; j++)
        pthread_join(threads[j], NULL);

    return 0;
}