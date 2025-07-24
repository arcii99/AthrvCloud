//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: interoperable
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 10

void *threadFunc(void *arg) {
    int *val = (int *)arg;
    printf("Thread %d started\n", *val);
    for (int i = 0; i < 3; i++) {
        printf("Thread %d looped %d times\n", *val, i+1);
    }
    printf("Thread %d ended\n", *val);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int threadArgs[MAX_THREADS];
    int rc, i;

    for (i = 0; i < MAX_THREADS; i++) {
        threadArgs[i] = i+1;
        printf("Creating thread %d\n", i+1);
        rc = pthread_create(&threads[i], NULL, threadFunc, (void *)&threadArgs[i]);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            return -1;
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            return -1;
        }
    }

    printf("All threads successfully joined.\n");
    pthread_exit(NULL);
}