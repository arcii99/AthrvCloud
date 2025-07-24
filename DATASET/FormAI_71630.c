//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;  // declare mutex lock

void* systemAdmin(void* threadId) {
    long id = (long) threadId;
    int successRate = rand() % 100 + 1;  // simulate success rate of system administration task
    
    pthread_mutex_lock(&lock);  // acquire lock
    
    printf("System Administrator %ld has started a task with a success rate of %d%%.\n", id, successRate);
    
    if (successRate < 80) {  // simulate failure
        printf("System Administrator %ld has failed to complete the task.\n", id);
    } else {
        printf("System Administrator %ld has successfully completed the task.\n", id);
    }
    
    pthread_mutex_unlock(&lock);  // release lock
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    srand(time(NULL));  // set seed for random number generator
    
    // create threads for system administration tasks
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, systemAdmin, (void*) t);
        if (rc) {  // handle error when creating thread
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
        sleep(1);  // introduce a delay between creating threads
    }
    
    // join threads
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {  // handle error when joining thread
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_mutex_destroy(&lock);  // destroy mutex lock
    pthread_exit(NULL);
}