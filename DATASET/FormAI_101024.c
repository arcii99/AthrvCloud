//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: happy
/* Happy Threading Library Implementation Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int thread_num = *((int *)arg);
    printf("Hello from thread %d!\n", thread_num);
    return NULL;
}

int main()
{
    int num_threads = 5;

    printf("Starting threading example!\n");

    pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * num_threads);
    int *thread_nums = (int *)malloc(sizeof(int) * num_threads);

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        thread_nums[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_nums[i])) {
            printf("Error creating thread!\n");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread!\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Finished threading example!\n");

    free(threads);
    free(thread_nums);

    return 0;
}