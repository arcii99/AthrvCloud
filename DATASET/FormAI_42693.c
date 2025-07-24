//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id){
    int *id_ptr = (int *) thread_id;
    int thread_id_val = *id_ptr;
    printf("Hello from thread %d\n", thread_id_val);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int rc, t;

    for(t=0;t<NUM_THREADS;t++){
        printf("Creating thread %d\n", t);
        thread_ids[t] = t;
        rc = pthread_create(&threads[t], NULL, print_hello, (void *) &thread_ids[t]);
        if (rc){
            printf("Error creating thread %d\n", t);
            exit(-1);
        }
    }

    pthread_exit(NULL);
    return 0;
}