//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_hello(void *thread_id)
{
    int id = *(int *) thread_id;
    printf("Thread %d: Hello, World!\n", id);
    pthread_exit(NULL);
}

int main()
{
    int num_threads = 5;
    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        int rc = pthread_create(&threads[i], NULL, print_hello, (void *) &thread_ids[i]);
        if (rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);

    return 0;
}