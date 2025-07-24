//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// function to be executed on a separate thread
void* thread_func(void* arg) {
    int* num = (int*) arg; // convert arg to integer pointer
    printf("Thread %d is running.\n", *num);
    free(num); // free dynamically allocated memory
    pthread_exit(NULL); // exit thread
}

int main() {
    pthread_t threads[5]; // create 5 threads
    int i;

    for (i = 0; i < 5; i++) {
        int* num = (int*) malloc(sizeof(int)); // dynamically allocate integer
        *num = i; // store i value in num
        if(pthread_create(&threads[i], NULL, thread_func, (void*) num)) { //create thread and pass num as arg
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    for (i = 0; i < 5; i++) {
        if(pthread_join(threads[i], NULL)) { // wait for each thread to finish
            printf("Error joining thread %d\n", i);
            exit(-1);
        }
    }

    printf("All threads have completed.\n");
    return 0;
}