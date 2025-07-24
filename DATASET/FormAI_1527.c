//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

pthread_t threads[MAX_THREADS];
char *messages[MAX_THREADS];

void *print_hello(void *thread_id) {
    int tid = *(int *)thread_id;
    printf("Thread %d: %s\n", tid, messages[tid]);
    pthread_exit(NULL);
}

int main(void) {
    int i;
 
    // Initialize messages
    messages[0] = "Hello";
    messages[1] = "World";
    messages[2] = "This";
    messages[3] = "Is";
    messages[4] = "A Thread!";

    // Create threads
    for (i = 0; i < MAX_THREADS; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        int rc = pthread_create(&threads[i], NULL, print_hello, id);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for threads to finish
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}