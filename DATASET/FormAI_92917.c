//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 10

pthread_t threads[MAX_THREADS]; // Define an array of threads
int data[MAX_THREADS]; // Define some data for each thread to manipulate

void* thread_function(void* arg) 
{
    int index = *(int*) arg; 

    printf("Thread %d starting...\n", index);

    data[index] = data[index-1] + data[index-2]; // Manipulate the data

    printf("Thread %d computed %d.\n", index, data[index]);

    pthread_exit(NULL); // Exit the thread
}

int main(int argc, char* argv[]) 
{
    int i;
    int indices[MAX_THREADS];
    data[0] = 0; // Initialize some data
    data[1] = 1;

    for (i = 2; i < MAX_THREADS; i++) 
    {
        indices[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &indices[i]); // Create the thread
    }

    for (i = 2; i < MAX_THREADS; i++) 
    {
        pthread_join(threads[i], NULL); // Wait for the thread to complete
    }

    printf("Data: ");
    for (i = 0; i < MAX_THREADS; i++) 
    {
        printf("%d ", data[i]); // Print the results
    }
    printf("\n");

    pthread_exit(NULL);
    return 0;
}