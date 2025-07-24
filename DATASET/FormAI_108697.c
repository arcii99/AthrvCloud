//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define ARRAY_SIZE 100
#define THREAD_COUNT 5

int arr[ARRAY_SIZE];
int search_key;
bool found = false;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* search(void* thread_id)
{
    int id = *(int*)thread_id;
    int start = id * (ARRAY_SIZE / THREAD_COUNT);
    int end = (id + 1) * (ARRAY_SIZE / THREAD_COUNT);

    for(int i = start; i < end; i++)
    {
        pthread_mutex_lock(&mutex);
        if(arr[i] == search_key)
        {
            printf("Key found at index %d by thread %d\n", i, id);
            found = true;
        }
        pthread_mutex_unlock(&mutex);

        if(found) break;
    }
}

int main()
{
    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];

    // initialize array with random values
    srand(time(NULL));
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 1000;
    }

    // get user input for search key
    printf("Enter search key: ");
    scanf("%d", &search_key);

    // create threads
    for(int i = 0; i < THREAD_COUNT; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, search, &thread_ids[i]);
    }

    // wait for threads to finish
    for(int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // if key was not found
    if(!found)
    {
        printf("Key not found\n");
    }

    return 0;
}