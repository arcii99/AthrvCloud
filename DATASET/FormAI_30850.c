//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
#define NUM_THREADS 5
 
void *thread_func(void *threadid);
 
int main() {
    pthread_t threads[NUM_THREADS];
    int rc, t;

    printf("Initializing cybernetic implants...\n");

    for(t=0; t<NUM_THREADS; t++){
        printf("Activating neural connection #%d\n", t+1);
        rc = pthread_create(&threads[t], NULL, thread_func, (void *)t);
        if (rc) {
            printf("Connection #%d failed to establish. Error code: %d\n", t+1, rc);
            exit(-1);
        }
    }

    printf("All connections are functional. Initiating neural network...\n");
    pthread_exit(NULL);
}
 
void *thread_func(void *threadid) {
    printf("Neural connection #%d is active.\n", (int)threadid+1);
    pthread_exit(NULL);
}