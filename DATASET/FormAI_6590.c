//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

// Define the number of threads to use
#define NUM_THREADS 4

// Define the array size
#define ARRAY_SIZE 1000

/* Global Variables */
int arr[ARRAY_SIZE];

/* A function to generate random numbers */
int get_random_number(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

/* A thread function to calculate the sum of the array */
void* array_sum(void* arg)
{
    int thread_num = *((int *) arg);
    int start = thread_num * (ARRAY_SIZE / NUM_THREADS);
    int end = start + (ARRAY_SIZE / NUM_THREADS);
    int sum = 0;
    
    for (int i = start; i < end; i++)
    {
        sum += arr[i];
    }
    
    return (void*) sum;
}

/* Main function */
int main()
{
    int i;
    int sum = 0;
    void* thread_result;
    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];
    
    // Seed the random number generator
    srand(time(0));
    
    // Initialize the array with random numbers
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = get_random_number(1, 10);
    }
    
    // Create the threads
    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, array_sum, &thread_nums[i]);
    }
    
    // Join the threads and get the sum of the array
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], &thread_result);
        sum += (int) thread_result;
    }
    
    // Print the sum of the array
    printf("The sum of the array is: %d\n", sum);
    
    return 0;
}