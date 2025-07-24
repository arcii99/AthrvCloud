//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int global_count = 0;
pthread_mutex_t lock;

void *increment_count(void *arg) {
    int *count = (int *) arg;
    pthread_mutex_lock(&lock);
    global_count += *count;
    fprintf(stdout, "Thread: %lu incremented count by %d.\n", pthread_self(), *count);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    int num_threads, counts_per_thread;
    printf("Enter number of threads to be created: ");
    scanf("%d", &num_threads);
    printf("Enter number of counts each thread should increment: ");
    scanf("%d", &counts_per_thread);
    pthread_t threads[num_threads];
    pthread_mutex_init(&lock, NULL);
    for(int i = 0; i < num_threads; i++) {
        int *count = malloc(sizeof(int));
        *count = counts_per_thread;
        pthread_create(&threads[i], NULL, increment_count, (void *) count);
    }
    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Global count after all threads executed: %d\n", global_count);
    pthread_mutex_destroy(&lock);
    return 0;
}