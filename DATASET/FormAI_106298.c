//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t lock;

void *print_message(void *thread_id) {
    long tid;
    tid = (long)thread_id;
    pthread_mutex_lock(&lock);
    printf("Thread #%ld: Entering paranoid section...\n", tid);
    printf("Thread #%ld: Checking surroundings...\n", tid);
    int random = rand() % 10;
    if(random >= 5){
        printf("Thread #%ld: Everything looks safe...\n", tid);
    } else {
        printf("Thread #%ld: ALERT! Possible danger detected! Exiting...\n", tid);
        exit(0);
    }
    printf("Thread #%ld: Exiting paranoid section safely.\n", tid);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0; t<NUM_THREADS; t++){
        rc = pthread_create(&threads[t], NULL, print_message, (void *)t);
        if (rc){
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_mutex_init(&lock, NULL);

    for(t=0; t<NUM_THREADS; t++){
        pthread_join(threads[t], NULL);
    }

    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
}