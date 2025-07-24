//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_THREADS 5

pthread_t threads[MAX_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int thread_count = 0;

void *thread_func(void *arg) {
    int id = *(int *)arg;
    printf("Thread %d is starting...\n", id);
    pthread_mutex_lock(&mutex);
    while (id != thread_count) {
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Thread %d is executing...\n", id);
    sleep(rand() % 5);
    thread_count++;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
    printf("Thread %d is finishing...\n", id);
    return NULL;
}

int main() {
    int ids[MAX_THREADS];
    srand(time(NULL));
    printf("Creating threads...\n");
    for (int i = 0; i < MAX_THREADS; i++) {
        ids[i] = i+1;
        if (pthread_create(&threads[i], NULL, thread_func, &ids[i]) != 0) {
            fprintf(stderr, "Error creating thread!\n");
            exit(1);
        }
    }
    printf("Threads created. Waiting for them to finish...\n");
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread!\n");
            exit(1);
        }
    }
    printf("All threads finished!\n");
    return 0;
}