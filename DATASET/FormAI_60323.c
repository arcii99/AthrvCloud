//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: systematic
/*
 * A simple implementation of a threading library in C.
 * This library allows to create new threads, pause and resume existing threads, and even de-allocate completed threads.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 100

/* Struct to hold thread information */
typedef struct {
    pthread_t tid;           // thread id
    bool is_allocated;       // whether thread has been allocated
    bool is_completed;       // whether thread has completed execution
    bool is_paused;          // whether thread is paused
} Thread;

Thread threads[MAX_THREADS];  // array to hold all threads info
int num_threads = 0;          // number of currently allocated threads

/* Function to create and start a new thread */
void start_new_thread(void *(*start_routine)(void *), void *arg) {
    // check if maximum number of threads has been reached
    if (num_threads == MAX_THREADS) {
        printf("Cannot allocate more threads. Maximum number of threads reached.\n");
        return;
    }
    
    // look for an unallocated thread
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        if (!threads[i].is_allocated) {
            break;
        }
    }
    
    // create new thread and save its info
    pthread_create(&threads[i].tid, NULL, start_routine, arg);
    threads[i].is_allocated = true;
    threads[i].is_completed = false;
    threads[i].is_paused = false;
    num_threads++;
}

/* Function to pause a thread */
void pause_thread(pthread_t tid) {
    // search for thread in thread array
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        if (threads[i].is_allocated && threads[i].tid == tid) {
            break;
        }
    }
    
    // pause thread if found
    if (i < MAX_THREADS) {
        threads[i].is_paused = true;
        printf("Thread %lu paused.\n", tid);
    } else {
        printf("Thread %lu not found.\n", tid);
    }
}

/* Function to resume a thread */
void resume_thread(pthread_t tid) {
    // search for thread in thread array
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        if (threads[i].is_allocated && threads[i].tid == tid) {
            break;
        }
    }
    
    // resume thread if found
    if (i < MAX_THREADS) {
        threads[i].is_paused = false;
        printf("Thread %lu resumed.\n", tid);
    } else {
        printf("Thread %lu not found.\n", tid);
    }
}

/* Function to deallocate a thread */
void deallocate_thread(pthread_t tid) {
    // search for thread in thread array
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        if (threads[i].is_allocated && threads[i].tid == tid) {
            break;
        }
    }
    
    // deallocate thread if found
    if (i < MAX_THREADS) {
        pthread_join(tid, NULL); // wait for thread to complete execution
        threads[i].is_allocated = false; // deallocate thread
        threads[i].is_completed = true;
        num_threads--;
        printf("Thread %lu deallocated.\n", tid);
    } else {
        printf("Thread %lu not found.\n", tid);
    }
}

/* Example function to be executed by threads */
void *my_function(void *arg) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Thread %lu executing. i = %d\n", pthread_self(), i);
        sleep(1);
        if (threads[i].is_paused) {
            while (threads[i].is_paused) {
                sleep(1); // wait for thread to be resumed
            }
        }
    }
    printf("Thread %lu completed.\n", pthread_self());
    return NULL;
}

/* Main function */
int main() {
    // create three threads
    start_new_thread(my_function, NULL);
    start_new_thread(my_function, NULL);
    start_new_thread(my_function, NULL);
    
    // pause and resume second thread
    sleep(4);
    pause_thread(threads[1].tid);
    sleep(3);
    resume_thread(threads[1].tid);
    sleep(4);
    
    // deallocate all threads and exit
    printf("Deallocating all threads.\n");
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        if (threads[i].is_allocated) {
            deallocate_thread(threads[i].tid);
        }
    }
    printf("Exiting main.\n");
    return 0;
}