//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_CNT 4

typedef struct {
    int id;
} thread_args_t;

void *start_routine(void *args) {
    thread_args_t *t_args = (thread_args_t *) args;
    printf("Thread %d started\n", t_args->id);

    // Do some work here

    printf("Thread %d finished\n", t_args->id);
    free(args);
    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[THREAD_CNT];
    int i;

    printf("Main thread started\n");
    for (i = 0; i < THREAD_CNT; i++) {
        thread_args_t *args = (thread_args_t *) malloc(sizeof(thread_args_t));
        args->id = i;
        if (pthread_create(&threads[i], NULL, start_routine, (void *) args)) {
            printf("Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    for (i = 0; i < THREAD_CNT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Main thread finished\n");
    return EXIT_SUCCESS;
}