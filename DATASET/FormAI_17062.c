//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

// Function to calculate Fibonacci sequence
void fibonacci(int n)
{
    int first = 0, second = 1, next;
    printf("%d %d ", first, second);
    for (int i = 2; i < n; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
    printf("\n");
}

void *printFibonacci(void* arg)
{
    int n = *((int*)arg);
    fibonacci(n);
    pthread_exit(NULL);
}

int main()
{
    int n1 = 10, n2 = 15;

    pthread_t thread1, thread2;

    // Creating threads
    pthread_create(&thread1, NULL, printFibonacci, &n1);
    pthread_create(&thread2, NULL, printFibonacci, &n2);

    // Waiting for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Threads finished executing.\n");

    return 0;
}