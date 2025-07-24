//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 10

int num_threads = 0; // global variable to keep track of number of threads
pthread_t threads[MAX_THREADS]; // array to store threads

// function to execute on thread
void *thread_func(void *arg) {
    int thread_num = *(int*)arg; // obtain thread number
    
    printf("Thread %d starting...\n", thread_num);
    sleep(1); // simulate some work
    printf("Thread %d stopping.\n", thread_num);
    
    return NULL;
}

// function to create threads
void create_threads(int num) {
    for(int i = 0; i < num; i++) {
        if(num_threads >= MAX_THREADS) { // check if maximum number of threads has been reached
            printf("Maximum number of threads reached!\n");
            return;
        }
        
        pthread_create(&threads[num_threads], NULL, thread_func, &num_threads); // create thread
        printf("Thread %d created.\n", num_threads);
        
        num_threads++; // increment number of threads
    }
}

int main() {
    printf("Creating 5 threads...\n");
    create_threads(5); // create 5 threads
    
    printf("Sleeping for 5 seconds...\n");
    sleep(5); // simulate some more work
    
    printf("Creating 10 more threads...\n");
    create_threads(10); // create 10 more threads
    
    printf("Sleeping for 10 seconds...\n");
    sleep(10); // simulate even more work
    
    printf("Exiting program.\n");
    return 0;
}