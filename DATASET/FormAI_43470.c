//FormAI DATASET v1.0 Category: Benchmarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000
#define MAX_THREADS 4

int array[ARRAY_SIZE];

// Function to initialize an array of random integers
void initArray(int *arr, int size){
    for(int i=0; i<size; i++){
        arr[i] = rand() % 100;
    }
}

// Function to calculate the sum of an array
int findSum(int *arr, int start, int end){
    int sum = 0;
    for(int i=start; i<end; i++){
        sum += arr[i];
    }
    return sum;
}

// Function to run each thread
void* threadFunction(void *arg){
    int threadIndex = *(int*)arg;
    int start = threadIndex*ARRAY_SIZE/MAX_THREADS;
    int end = (threadIndex+1)*ARRAY_SIZE/MAX_THREADS;
    int *sum = malloc(sizeof(int));
    if(!sum){
        printf("Memory allocation error!\n");
        exit(1);
    }
    *sum = findSum(array, start, end);
    pthread_exit(sum);
}

int main(){
    srand(time(NULL));
    initArray(array, ARRAY_SIZE);

    // Create an array to store the thread IDs
    pthread_t threads[MAX_THREADS];

    // Create an array to store the thread argument (i.e. the thread index)
    int threadArgs[MAX_THREADS];

    // Create an array to store the thread return value (i.e. the sum)
    int *sums[MAX_THREADS];

    for(int i=0; i<MAX_THREADS; i++){
        threadArgs[i] = i;
        // Create a new thread
        if(pthread_create(&threads[i], NULL, threadFunction, (void *)&threadArgs[i])){
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }

    // Join each thread and get the return value (i.e. the sum)
    for(int i=0; i<MAX_THREADS; i++){
        if(pthread_join(threads[i], (void **)&sums[i])){
            printf("Error joining thread %d\n", i);
            exit(1);
        }
    }

    // Calculate the final sum
    int finalSum = 0;
    for(int i=0; i<MAX_THREADS; i++){
        finalSum += *sums[i];
        free(sums[i]);
    }

    printf("The sum of the array is: %d\n", finalSum);

    return 0;
}