//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10

int cpu_usage;
pthread_mutex_t mutex;

void *monitor_cpu_usage(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        cpu_usage = rand() % 100 + 1;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *display_cpu_usage(void *arg) {
    int thread_id = *(int *)arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        printf("Thread %d CPU usage: %d%%\n", thread_id, cpu_usage);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t monitor_thread, display_threads[MAX_THREADS];
    pthread_create(&monitor_thread, NULL, monitor_cpu_usage, NULL);

    for (int i = 0; i < MAX_THREADS; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&display_threads[i], NULL, display_cpu_usage, arg);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(display_threads[i], NULL);
    }

    pthread_cancel(monitor_thread);
    pthread_mutex_destroy(&mutex);
    return 0;
}