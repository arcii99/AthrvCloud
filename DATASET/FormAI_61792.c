//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: scientific
/* 
  Program: C Threading Library Implementation Example Program 
  Author: [Your Name]
  Date: [Date]

  Description: This program demonstrates the implementation of a simple
  custom threading library using C language.

  Citation: [List any resources or references used in creating the program.]

*/

/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

/* Macro definitions */
#define MAX_THREADS 5
#define MAX_LOOP_COUNT 5

/* Structure definition */
struct Thread {
    int id;
    bool in_use;
    bool work_done;
    pthread_t pthread_id;
};

/* Global variables */
struct Thread thread_pool[MAX_THREADS];
pthread_mutex_t pool_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Function prototypes */
void* threadFunction(void* arg);
int getAvailableThreadId();
void initializeThreadPool();
void destroyThreadPool();

/* Main function */
int main(int argc, char **argv){
    initializeThreadPool();

    for(int i=0; i<MAX_LOOP_COUNT; i++){
        int thread_id = getAvailableThreadId();

        /* Execute thread*/
        pthread_create(&thread_pool[thread_id].pthread_id, NULL, threadFunction, &thread_pool[thread_id]);

        pthread_join(thread_pool[thread_id].pthread_id, NULL);

        /* Update thread status*/
        thread_pool[thread_id].work_done = true;
        thread_pool[thread_id].in_use = false;
    }

    destroyThreadPool();

    return 0;
}

/* Function definitions */

/* The threadFunction function is called when a thread is executed and will perform a simple task.*/
void* threadFunction(void* arg){
    struct Thread* thread = (struct Thread*) arg;

    printf("Thread %d executing...\n", thread->id);

    /* Simulate some work */
    sleep(1);

    printf("Thread %d completed.\n", thread->id);

    return NULL;
}

/* The getAvailableThreadId function returns the ID of an available thread 
   from the thread pool, to be used for executing a new thread.*/
int getAvailableThreadId(){
    pthread_mutex_lock(&pool_mutex);

    for(int i=0; i<MAX_THREADS; i++){
        if(!thread_pool[i].in_use){
            thread_pool[i].in_use = true;
            pthread_mutex_unlock(&pool_mutex);
            return i;
        }
    }

    pthread_mutex_unlock(&pool_mutex);
    return -1;
}

/* The initializeThreadPool function initializes all the threads in the thread pool*/
void initializeThreadPool(){
    for(int i=0; i<MAX_THREADS; i++){
        thread_pool[i].id = i;
        thread_pool[i].in_use = false;
        thread_pool[i].work_done = false;
    }
}

/* The destroyThreadPool function joins all threads in pool, and 
   destroys the mutex used to protect the pool access */
void destroyThreadPool(){
    for(int i=0; i<MAX_THREADS; i++){
        if(thread_pool[i].in_use){
            pthread_join(thread_pool[i].pthread_id, NULL);
        }
    }

    pthread_mutex_destroy(&pool_mutex);
}