//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 4

pthread_t thread_ids[THREADS]; // declaring thread ids array
int array[100];
int global_sum = 0;

void *Sum(void *arg)
{
    int thread_num = *(int *)arg; // getting thread number as argument
    int sum = 0;
    for(int i = thread_num * 25; i < (thread_num + 1) * 25; i++)
    {
        sum += array[i];
    }
    global_sum += sum; // updating global sum with each thread's sum
    pthread_exit(NULL); // exiting thread
}

int main()
{
    for(int i = 0; i < 100; i++)
    {
        array[i] = i + 1; // initializing array
    }
    
    // creating threads
    for(int i = 0; i < THREADS; i++)
    {
        int *thread_num = malloc(sizeof(int)); // allocating memory for argument
        *thread_num = i;
        pthread_create(&thread_ids[i], NULL, Sum, (void *)thread_num);
    }
    
    // joining threads
    for(int i = 0; i < THREADS; i++)
    {
        pthread_join(thread_ids[i], NULL);
    }
    
    printf("The sum of all elements in the array is %d.", global_sum); // printing global sum
    
    return 0;
}