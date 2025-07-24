//FormAI DATASET v1.0 Category: Funny ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 10 //number of threads
#define MAX_ARRAY_SIZE 1000 //maximum size of the array

void *sumArray(void *arg);
int getRandomNum();

//global variables
int array[MAX_ARRAY_SIZE];
int sum = 0;

int main()
{
    srand((unsigned)time(NULL)); //initialize random number generator

    pthread_t threads[THREADS]; //array of threads

    printf("Generating array of %d random numbers...\n", MAX_ARRAY_SIZE);
    for(int i = 0; i < MAX_ARRAY_SIZE; i++) {
        array[i] = getRandomNum(); //populate array with random numbers
    }

    printf("Creating %d threads...\n", THREADS);
    for(int i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, sumArray, (void *)i); //create new thread
    }

    printf("Waiting for threads to finish...\n");
    for(int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL); //wait for threads to finish
    }

    printf("The sum of the array is: %d\n", sum);

    return 0;
}

void *sumArray(void *arg)
{
    int threadId = (int)arg; //cast void pointer to int
    int start = threadId * (MAX_ARRAY_SIZE / THREADS); //start index for thread
    int end = start + (MAX_ARRAY_SIZE / THREADS); //end index for thread

    for(int i = start; i < end; i++) {
        sum += array[i]; //add to global sum variable
    }

    pthread_exit(NULL); //exit thread
}

int getRandomNum()
{
    return (rand() % 100) + 1; //returns random number between 1 and 100
}