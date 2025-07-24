//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int counter = 0;
const int MAX_COUNTER = 10;

void *increment_counter(void *thread_id) {
    long tid = (long) thread_id;
    printf("Thread #%ld is starting\n", tid);
    
    while (counter < MAX_COUNTER) {
        pthread_mutex_lock(&mutex);
        printf("Thread #%ld acquired the lock\n", tid);
        counter++;
        printf("Thread #%ld incremented the counter to %d\n", tid, counter);
        if (counter == 5) {
            printf("Thread #%ld encountered an error\n", tid);
            pthread_mutex_unlock(&mutex); // We unlock the mutex before exiting the thread
            pthread_exit((void*) "Encountered an error");
        }
        pthread_mutex_unlock(&mutex);
        sleep(1); // We wait for a second before incrementing again
    }
    
    printf("Thread #%ld has finished\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int rc;
    long t;
    void *status;
    
    pthread_mutex_init(&mutex, NULL);
    
    for (t = 0; t < 3; t++) {
        rc = pthread_create(&threads[t], NULL, increment_counter, (void*) t);
        if (rc) {
            printf("Error: Can't create thread #%ld\n", t);
            exit(-1);
        }
    }
    
    for (t = 0; t < 3; t++) {
        rc = pthread_join(threads[t], &status);
        if (rc) {
            printf("Error: Can't join thread #%ld\n", t);
            exit(-1);
        }
        printf("Main: Thread #%ld finished with status: %s\n", t, (char*) status);
    }
    
    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
}