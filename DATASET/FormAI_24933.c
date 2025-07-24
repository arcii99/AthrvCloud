//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *arg)
{
    int tid;

    tid = (int)arg;
    printf("Thread %d is starting...\n",tid);
    sleep(3);
    printf("Thread %d is done.\n",tid);

    return NULL;
}

int main(void)
{
    pthread_t threads[NUM_THREADS];
    int i, rc;

    for (i=0; i<NUM_THREADS; i++) {
        printf("Main: creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, thread_function, (void *)i);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* wait for threads to finish */
    for (i=0; i<NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        printf("Main: thread %d has finished\n", i);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    printf("Main: program exiting\n");
    return 0;
}