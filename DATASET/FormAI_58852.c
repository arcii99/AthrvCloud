//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_CNT 3

int counter = 0;
int shared_array[100] = {0};
pthread_mutex_t mutex;

void *thread_func(void *arg) {
    int thread_id = *(int*) arg;

    for(int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        printf("Thread %d: Counter = %d\n", thread_id, counter);
        shared_array[counter] = thread_id;
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_CNT];
    int thread_ids[THREAD_CNT] = {0, 1, 2};
    int ret;

    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < THREAD_CNT; i++) {
        printf("Creating Thread %d\n", i);
        ret = pthread_create(&threads[i], NULL, &thread_func, (void*) &thread_ids[i]);
        if(ret) {
            printf("ERROR: pthread_create: %d\n", ret);
            exit(-1);
        }
    }

    for(int i = 0; i < THREAD_CNT; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    for(int i = 1; i <= counter; i++) {
        printf("%d ", shared_array[i]);
    }

    printf("\n");

    return 0;
}