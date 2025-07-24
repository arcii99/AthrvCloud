//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

void* print_message(void* thread_id){
    int tid = *(int*)thread_id;
    printf("Thread %d says hello\n", tid);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i, rc;

    printf("Creating threads...\n");
    for (i = 0; i < NUM_THREADS; i++){
        printf("Creating thread %d\n", i);
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, print_message, (void*)&thread_ids[i]);
        if (rc){
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    printf("Waiting for threads to finish...\n");
    for (i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
        printf("Thread %d has finished\n", i);
    }

    printf("All threads have finished. Exiting.\n");
    pthread_exit(NULL);
    return 0;
}