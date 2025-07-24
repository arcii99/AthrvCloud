//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_thread_id(void *thread_id) {
    int *id = (int *)thread_id;
    printf("Hello from thread %d\n", *id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        int rc = pthread_create(&threads[i], NULL, print_thread_id, (void *)&thread_ids[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            return 1;
        }
    }

    pthread_exit(NULL);
}