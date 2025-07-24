//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_COUNT 10000000

int count = 0;
pthread_mutex_t mutex;

void* increment_counter(void* arg) {
    for(int i=0; i<MAX_COUNT; i++) {
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final count value: %d\n", count);

    return 0;
}