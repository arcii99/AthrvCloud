//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_message(void *message_ptr) {
    char *message = (char *) message_ptr;
    printf("%s\n", message);
}

int main() {
    pthread_t threads[NUM_THREADS];
    char *messages[NUM_THREADS] = {
        "Thread 1",
        "Thread 2",
        "Thread 3",
        "Thread 4",
        "Thread 5"
    };

    int i, rc;
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, print_message, (void *) messages[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }

        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
    return 0;
}