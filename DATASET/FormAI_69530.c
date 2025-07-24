//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed as thread
void *thread_func(void *arg) {
    int thread_num = *(int *)arg;
    printf("Thread %d is running\n", thread_num);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    int thread_nums[4] = {1, 2, 3, 4};
    int rc;

    // Create four threads
    for (int i = 0; i < 4; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *)&thread_nums[i]);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < 4; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads have completed successfully\n");

    return 0;
}