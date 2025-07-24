//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void* threadFunc(void* arg) {
    int thread_num = *(int*) arg;
    printf("Thread %d starting...\n", thread_num);
    int sum = 0;
    for (int i = 0; i <= thread_num; i++) {
        sum += i;
    }
    printf("Thread %d finished with sum = %d.\n", thread_num, sum);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int return_code;
    int thread_count;

    for (thread_count = 0; thread_count < NUM_THREADS; thread_count++) {
        thread_args[thread_count] = thread_count;
        printf("Creating Thread %d...\n", thread_count);
        return_code = pthread_create(&threads[thread_count], NULL, threadFunc, &thread_args[thread_count]);
        if (return_code) {
            printf("ERROR; return code from pthread_create() is %d\n", return_code);
            exit(-1);
        }
    }

    printf("All threads created. Now waiting for them to finish...\n");

    for (thread_count = 0; thread_count < NUM_THREADS; thread_count++) {
        return_code = pthread_join(threads[thread_count], NULL);
        if (return_code) {
            printf("ERROR; return code from pthread_join() is %d\n", return_code);
            exit(-1);
        }
        printf("Thread %d has finished.\n", thread_count);
    }

    printf("All threads have finished. Exiting.\n");
    pthread_exit(NULL);
}