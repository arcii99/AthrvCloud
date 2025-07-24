//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

/* Define a thread struct for holding thread-related information */
typedef struct thread {
    pthread_t thread_id;
    int thread_num;
    char *message;
} thread_t;

/* Define a function that will be executed by the thread */
void *thread_func(void *arg) {
    thread_t *td = (thread_t*) arg;
    printf("Thread %d: %s\n", td->thread_num, td->message);
    pthread_exit(NULL);
}

/* Define the main function */
int main(int argc, char *argv[]) {

    int num_threads = 5;
    thread_t *threads = malloc(sizeof(thread_t) * num_threads);

    /* Create and run each thread */
    for (int i = 0; i < num_threads; i++) {
        threads[i].thread_num = i + 1;
        threads[i].message = "Hello from thread!";
        pthread_create(&(threads[i].thread_id), NULL, thread_func, &(threads[i]));
    }

    /* Wait for each thread to complete */
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i].thread_id, NULL);
    }

    /* Free memory used for threads */
    free(threads);

    return 0;
}