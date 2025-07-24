//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex;
int count = 0;

void *print_count(void *thread_id) {
    int i;
    printf("Thread %ld starting...\n", (long)thread_id);

    pthread_mutex_lock(&mutex);
    for (i = 0; i < 10; i++) {
        count++;
        printf("Thread %ld count = %d\n", (long)thread_id, count);
    }
    pthread_mutex_unlock(&mutex);

    printf("Thread %ld ending...\n", (long)thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, t;

    pthread_mutex_init(&mutex, NULL);

    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, print_count, (void *)t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
}