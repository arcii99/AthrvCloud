//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

void *print_message(void *thread_id)
{
    int tid = *(int *)thread_id;
    printf("Thread %d is running.\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    int i, rc;

    for(i=0; i<MAX_THREADS; i++) {
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, print_message, (void *)&thread_ids[i]);
        if(rc) {
            printf("ERROR: return code from pthread_create() is %d.\n", rc);
            exit(1);
        }
    }

    printf("All threads are created and running.\n");

    for(i=0; i<MAX_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if(rc) {
            printf("ERROR: return code from pthread_join() is %d.\n", rc);
            exit(1);
        }
        printf("Thread %d is joined.\n", i);
    }

    printf("All threads are joined and completed.\n");

    pthread_exit(NULL);
    return 0;
}