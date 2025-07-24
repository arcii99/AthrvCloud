//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_print(void *thread_id) {
    int thread_num = *(int*)thread_id;
    printf("Hello from thread %d!\n", thread_num);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        int rc = pthread_create(&threads[i], NULL, thread_print, (void *)&thread_ids[i]);
        if (rc) {
            printf("ERROR: Unable to create thread %d. Return code: %d\n", i+1, rc);
            exit(-1);
        }
    }

    /* Wait for threads to finish */
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads complete.\n");

    pthread_exit(NULL);
}