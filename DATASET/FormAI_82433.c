//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *thread_function(void *thread_id) {
   int *id_ptr, task_id;

   id_ptr = (int *) thread_id;    /* Get the actual thread id */
   task_id = *id_ptr;
   printf("Thread %d: starting...\n", task_id);
   sleep(2);
   printf("Thread %d: finishing...\n", task_id);
   return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int *taskids[NUM_THREADS];
    int i, rc;

    /* Create threads */
    for (i=0; i<NUM_THREADS; i++) {
        taskids[i] = (int *) malloc(sizeof(int));
        *taskids[i] = i;
        printf("Creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, thread_function, (void *) taskids[i]);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* Wait for all threads to complete */
    for (i=0; i<NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        printf("Main: completed join with thread %d having a status of %d\n", i, rc);
    }

    printf("Main: program completed. Exiting.\n");
    return 0;
}