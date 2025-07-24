//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Define the number of threads */
#define NUM_THREADS 4

/* Define a struct to hold thread arguments */
typedef struct {
    int thread_id;
} thread_arg;

/* Define the function to be executed by each thread */
void* thread_function(void* arg) {
    thread_arg* t_arg = (thread_arg*) arg;
    printf("Hello from thread %d\n", t_arg->thread_id);
    pthread_exit(NULL);
}

/* Main function, creates and joins threads */
int main(int argc, char* argv[]) {
    pthread_t threads[NUM_THREADS]; /* Array of thread IDs */
    thread_arg* args[NUM_THREADS]; /* Array of thread argument pointers */
    int rc, i;

    /* Create threads */
    for (i = 0; i < NUM_THREADS; i++) {
        args[i] = (thread_arg*) malloc(sizeof(thread_arg));
        args[i]->thread_id = i;
        rc = pthread_create(&threads[i], NULL, thread_function, (void*) args[i]);
        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    /* Join threads */
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error joining thread %d\n", i);
            exit(-1);
        }
        free(args[i]);
    }

    return 0;
}