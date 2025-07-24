//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 4
#define WORK_COUNT 10

/* This structure represents a unit of work */
typedef struct work_struct {
    int id;
} work_t;

/* This function is executed by each thread */
void* thread_func(void* arg) {
    work_t* work = (work_t*) arg;
    printf("Thread %lu starting work %d\n", pthread_self(), work->id);
    /* Do some work */
    printf("Thread %lu finished work %d\n", pthread_self(), work->id);
    free(work);
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int i, j;

    /* Queue up some work */
    for (i = 0; i < WORK_COUNT; i++) {
        work_t* work = (work_t*) malloc(sizeof(work_t));
        work->id = i;
        /* Choose a random thread to execute this work */
        j = rand() % THREAD_COUNT;
        pthread_create(&threads[j], NULL, thread_func, work);
    }

    /* Wait for all threads to finish */
    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All work completed!\n");
    return 0;
}