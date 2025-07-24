//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *worker_function(void *arg){
    int thread_num = *(int*)arg;
    printf("Thread %d started working...\n", thread_num);

    // do some work
    int i;
    for(i=0; i<1000000; i++);
    
    printf("Thread %d finished working.\n", thread_num);
    return NULL;
}

int main(){
    pthread_t threads[10];
    int thread_args[10];

    int i;
    for(i=0; i<10; i++){
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, worker_function, (void*)&thread_args[i]);
    }

    for(i=0; i<10; i++){
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished working.\n");

    return 0;
}