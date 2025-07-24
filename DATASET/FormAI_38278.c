//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
int sum; /* sum shared by the threads */
pthread_mutex_t mutex; /* mutex for locking critical section */
 
/* thread function for adding values from start to end to sum */
void *thread_sum(void *arg) {
    int start = *((int *)arg); /* start value */
    int end = start + 10000; /* end value */
 
    for(int i = start; i < end; i++) {
        pthread_mutex_lock(&mutex);
        sum += i;
        pthread_mutex_unlock(&mutex);
    }
 
    pthread_exit(NULL);
}
 
int main() {
    pthread_t threads[10];
    int start_points[10];
    sum = 0;
 
    /* initialize mutex */
    if(pthread_mutex_init(&mutex, NULL) != 0) {
        fprintf(stderr, "Mutex initialization failed.\n");
        exit(EXIT_FAILURE);
    }
 
    /* create and launch threads */
    for(int i = 0; i < 10; i++) {
        start_points[i] = i * 10000;
        if(pthread_create(&threads[i], NULL, thread_sum, (void *)&start_points[i]) != 0) {
            fprintf(stderr, "Error creating thread.\n");
            exit(EXIT_FAILURE);
        }
    }
 
    /* wait for threads to finish and sum their return values */
    for(int i = 0; i < 10; i++) {
        if(pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread.\n");
            exit(EXIT_FAILURE);
        }
    }
 
    /* destroy mutex */
    pthread_mutex_destroy(&mutex);
 
    printf("The sum is: %d\n", sum);
 
    return 0;
}