//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS  4
#define VECTOR_SIZE  1000000

typedef struct
{
    int *vector1;
    int *vector2;
    int start_index;
    int end_index;
    long long result;
} thread_args;

void *dot_product(void *input_args)
{
    thread_args *args = (thread_args*)input_args;
    for (int i = args->start_index; i < args->end_index; i++)
    {
        args->result += args->vector1[i] * args->vector2[i];
    }
    pthread_exit(NULL);
}

int main()
{
    int vector1[VECTOR_SIZE];
    int vector2[VECTOR_SIZE];
    long long result = 0;

    pthread_t threads[NUM_THREADS];
    thread_args args[NUM_THREADS];

    srand(0);
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        vector1[i] = rand() % 10;
        vector2[i] = rand() % 10;
    }

    int chunk_size = VECTOR_SIZE / NUM_THREADS;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        args[i].vector1 = vector1;
        args[i].vector2 = vector2;
        args[i].start_index = i * chunk_size;
        args[i].end_index = (i == NUM_THREADS - 1) ? VECTOR_SIZE : (i + 1) * chunk_size;
        args[i].result = 0;
        pthread_create(&threads[i], NULL, dot_product, (void*)&args[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
        result += args[i].result;
    }

    printf("Dot product is: %lld\n", result);

    return 0;
}