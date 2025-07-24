//FormAI DATASET v1.0 Category: Game ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_message(void *thread_id) {
    int *id_ptr = (int*)thread_id;
    int task_id = *id_ptr;
    printf("Thread with ID %d is running\n", task_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int task_ids[NUM_THREADS];
    int rc, i;

    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        task_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, print_message, (void *)&task_ids[i]);
        if (rc) {
            printf("ERROR: Unable to create thread %d\n", rc);
            return -1;
        }
    }

    pthread_exit(NULL);
    return 0;
}