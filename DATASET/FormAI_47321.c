//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Romeo and Juliet
/* Romeo and Juliet Threading Library Implementation Example Program */

// Prologue
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Function Declarations
void *romeo_routine(void *);
void *juliet_routine(void *);

// Global Variables
pthread_mutex_t balcony_mutex;
pthread_cond_t romeo_cond, juliet_cond;

// Main Function
int main(void) {
    pthread_t romeo_thread, juliet_thread;
    pthread_mutex_init(&balcony_mutex, NULL);
    pthread_cond_init(&romeo_cond, NULL);
    pthread_cond_init(&juliet_cond, NULL);
    pthread_create(&juliet_thread, NULL, juliet_routine, NULL);
    pthread_create(&romeo_thread, NULL, romeo_routine, NULL);
    pthread_join(juliet_thread, NULL);
    pthread_join(romeo_thread, NULL);
    pthread_mutex_destroy(&balcony_mutex);
    pthread_cond_destroy(&romeo_cond);
    pthread_cond_destroy(&juliet_cond);
    return 0;
}

// Romeo Thread Routine
void *romeo_routine(void *arg) {
    while (1) {
        printf("Romeo: Arrives at the Balcony!\n");
        pthread_mutex_lock(&balcony_mutex);
        printf("Romeo: Sees that the balcony is empty!\n");
        pthread_cond_signal(&juliet_cond);
        pthread_cond_wait(&romeo_cond, &balcony_mutex);
        printf("Romeo: Sees Juliet on the Balcony!\n");
        sleep(2);
        printf("Romeo: Leaves the Balcony!\n\n");
        pthread_mutex_unlock(&balcony_mutex);
        sleep(1);
    }
}

// Juliet Thread Routine
void *juliet_routine(void *arg) {
    while (1) {
        printf("Juliet: Arrives at the Balcony!\n");
        pthread_mutex_lock(&balcony_mutex);
        pthread_cond_wait(&juliet_cond, &balcony_mutex);
        printf("Juliet: Sees Romeo on the Balcony!\n");
        sleep(2);
        printf("Juliet: Signals Romeo to leave the Balcony!\n");
        pthread_cond_signal(&romeo_cond);  
        pthread_mutex_unlock(&balcony_mutex);
        sleep(1);
    }
}

// Epilogue