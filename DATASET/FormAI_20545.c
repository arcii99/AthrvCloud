//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 10
#define MESSAGE_COUNT 5

pthread_t threads[THREAD_COUNT];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg) {
    int thread_id = *((int*) arg);
    for (int i = 0; i < MESSAGE_COUNT; i++) {
        pthread_mutex_lock(&mutex);
        printf("Thread %d says: We are the last survivors. The world is destroyed.\n", thread_id);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    printf("Welcome to the post-apocalyptic world. The world as we knew it, has been destroyed.\n");
    sleep(1);
    printf("We are the last remaining survivors. We have to work together to survive.\n");
    sleep(1);

    // Spawn threads
    int thread_ids[THREAD_COUNT];
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i+1;
        int result = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
        if (result != 0) {
            printf("Thread creation failed with error code %d.\n", result);
            exit(1);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("We have survived another day, but the world is still dangerous.\n");
    printf("We must remain united and support each other, if we hope to rebuild.\n");

    return 0;
}