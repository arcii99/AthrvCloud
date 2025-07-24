//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *thread_id){
    int tid = *((int*)thread_id);
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);
}

//function to create threads
void create_threads(pthread_t *threads){
    int i, *thread_id;

    for (i = 0; i < NUM_THREADS; i++){
        thread_id = malloc(sizeof(int));
        *thread_id = i;
        pthread_create(&threads[i], NULL, thread_func, (void *)thread_id);
    }
}

//function to join threads
void join_threads(pthread_t *threads){
    int i;

    for (i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
}

int main(){
    pthread_t threads[NUM_THREADS];

    create_threads(threads);
    join_threads(threads);

    return 0;
}