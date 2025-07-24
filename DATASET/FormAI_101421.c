//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *thread_id){
    int tid = *(int *)thread_id;
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int i, rc;
    
    for(i=0; i<NUM_THREADS; i++){
        printf("Creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, thread_function, &i);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}