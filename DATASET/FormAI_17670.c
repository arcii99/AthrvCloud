//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 3

pthread_t threads[MAX_THREADS];
int status[MAX_THREADS];

void *threadFunc(void *arg) {
    int *tid = (int *) arg;
    printf("Thread %d: started\n", *tid);
    // Perform some system administration function here
    status[*tid] = 1;
    printf("Thread %d: completed\n", *tid);
    pthread_exit(NULL);
}

int main() {
    int i, threadArgs[MAX_THREADS];
    memset(status, 0, sizeof(status));
    
    for (i = 0; i < MAX_THREADS; i++) {
        threadArgs[i] = i;
        if(pthread_create(&threads[i], NULL, threadFunc, &threadArgs[i]) != 0) {
            perror("Cannot create thread");
            exit(-1);
        }
    }
    
    for (i = 0; i < MAX_THREADS; i++) {
        if(pthread_join(threads[i], NULL) != 0) {
            perror("Cannot join thread");
            exit(-1);
        }
    }
    
    printf("All threads completed\n");
    return 0;
}