//FormAI DATASET v1.0 Category: Arithmetic ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to add two integers
void* add(void* arg)
{
    int* args = (int*)arg;
    int sum = args[0] + args[1];
    printf("Sum: %d\n", sum);
    pthread_exit(NULL);
}

// Function to subtract two integers
void* subtract(void* arg)
{
    int* args = (int*)arg;
    int diff = args[0] - args[1];
    printf("Difference: %d\n", diff);
    pthread_exit(NULL);
}

// Function to multiply two integers
void* multiply(void* arg)
{
    int* args = (int*)arg;
    int product = args[0] * args[1];
    printf("Product: %d\n", product);
    pthread_exit(NULL);
}

// Function to divide two integers
void* divide(void* arg)
{
    int* args = (int*)arg;
    int quotient = args[0] / args[1];
    printf("Quotient: %d\n", quotient);
    pthread_exit(NULL);
}

int main()
{
    int num1 = 20, num2 = 10;

    pthread_t threads[4];

    // Arguments to pass to the addition thread
    int addArgs[2] = { num1, num2 };
    // Arguments to pass to the subtraction thread
    int subtractArgs[2] = { num1, num2 };
    // Arguments to pass to the multiplication thread
    int multiplyArgs[2] = { num1, num2 };
    // Arguments to pass to the division thread
    int divideArgs[2] = { num1, num2 };

    // Create addition thread
    pthread_create(&threads[0], NULL, add, (void*)addArgs);
    // Create subtraction thread
    pthread_create(&threads[1], NULL, subtract, (void*)subtractArgs);
    // Create multiplication thread
    pthread_create(&threads[2], NULL, multiply, (void*)multiplyArgs);
    // Create division thread
    pthread_create(&threads[3], NULL, divide, (void*)divideArgs);

    // Wait for all threads to finish
    for (int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}