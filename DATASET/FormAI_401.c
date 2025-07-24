//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

void* thread_function(void* arg)
{
    int thread_id = *(int*)arg;
    printf("Cyberpunk Thread %d running...\n", thread_id);
    sleep(3);
    printf("Cyberpunk Thread %d exiting...\n", thread_id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int rc, i;

    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating Cyberpunk Thread %d...\n", i);
        thread_args[i] = i;
        rc = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
        if (rc) {
            printf("Error creating Cyberpunk Thread %d; return code from pthread_create() is %d\n", i, rc);
            exit(-1);
        }
    }

    printf("Cyberpunk Main Thread waiting for Cyberpunk Threads to exit...\n");

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error joining Cyberpunk Thread %d; return code from pthread_join() is %d\n", i, rc);
            exit(-1);
        }
        printf("Cyberpunk Thread %d joined\n", i);
    }

    printf("Cyberpunk Main Thread exiting\n");
    pthread_exit(NULL);
}