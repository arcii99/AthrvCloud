//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

int counter = 0;
pthread_mutex_t mutex_lock;

void *thread_function(void *arg) {
    int i;

    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex_lock);
        counter++;
        printf("Thread %ld incremented counter to %d\n", (long) arg, counter);
        pthread_mutex_unlock(&mutex_lock);
        sleep(1);
    }

    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[MAX_THREADS];
    int rc, i;

    pthread_mutex_init(&mutex_lock, NULL);
    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_function, (void *) i);
        if (rc) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            perror("pthread_join failed");
            exit(EXIT_FAILURE);
        }
    }

    pthread_mutex_destroy(&mutex_lock);
    printf("Final value of counter is %d\n", counter);

    return EXIT_SUCCESS;
}