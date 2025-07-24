//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Claude Shannon
/* This program demonstrates an implementation of a custom threading library using c language */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

/* custom thread struct */
struct thread_info {
    pthread_t thread_id;
    int thread_num;
};

typedef struct thread_info ThreadInfo;

/* Thread function that simply prints the thread number */
void* thread_func(void* arg) {
    ThreadInfo* tinfo = (ThreadInfo*) arg;
    printf("Thread %d started\n", tinfo->thread_num);
    pthread_exit(NULL);
}

int main() {
    int i;
    ThreadInfo threads[NUM_THREADS];

    /* Create the threads */
    for (i = 0; i < NUM_THREADS; ++i) {
        threads[i].thread_num = i;
        if (pthread_create(&threads[i].thread_id, NULL, &thread_func, (void*)&threads[i]) != 0) {
            perror("thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    /* Wait for the threads to complete */
    for (i = 0; i < NUM_THREADS; ++i) {
        if (pthread_join(threads[i].thread_id, NULL) != 0) {
            perror("thread join failed");
            exit(EXIT_FAILURE);
        }
        printf("Thread %d exited\n", threads[i].thread_num);
    }

    pthread_exit(NULL);
}