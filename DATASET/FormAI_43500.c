//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* This program will create three threads that will print "Happy", "Thread", and "Day" in random order. */

void* printHappy(void* arg) {
    printf("Happy ");
    pthread_exit(NULL);
}

void* printThread(void* arg) {
    printf("Thread ");
    pthread_exit(NULL);
}

void* printDay(void* arg) {
    printf("Day\n");
    pthread_exit(NULL);
}

int main(void) {
    pthread_t thread1, thread2, thread3;
    int error1, error2, error3;
    
    // Create thread 1
    error1 = pthread_create(&thread1, NULL, printHappy, NULL);
    if (error1) {
        fprintf(stderr, "Error creating thread 1");
        exit(EXIT_FAILURE);
    }
    
    // Create thread 2
    error2 = pthread_create(&thread2, NULL, printThread, NULL);
    if (error2) {
        fprintf(stderr, "Error creating thread 2");
        exit(EXIT_FAILURE);
    }
    
    // Create thread 3
    error3 = pthread_create(&thread3, NULL, printDay, NULL);
    if (error3) {
        fprintf(stderr, "Error creating thread 3");
        exit(EXIT_FAILURE);
    }
    
    // Wait for all threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}