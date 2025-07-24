//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: happy
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int global_variable = 0;

pthread_mutex_t lock;

void* increment_value(void* arg) {
    int id = *((int*) arg);
    while (1) {
        pthread_mutex_lock(&lock);

        if (global_variable >= 10) {
            pthread_mutex_unlock(&lock);
            break;
        }

        printf("Thread %d incrementing value to: %d\n", id, ++global_variable);

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main(int argc, char const *argv[]) {
    pthread_mutex_init(&lock, NULL);

    int num_threads = 5;
    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, increment_value, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}