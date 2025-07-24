//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 4

pthread_mutex_t lock;
pthread_cond_t cond_var;

int task_available;
int tasks_handled;

void* worker_thread(void* arg){
    int thread_id = (int)arg;
    printf("Worker Thread %d started.\n", thread_id);

    while (1){
        pthread_mutex_lock(&lock);
        while(!task_available){
            pthread_cond_wait(&cond_var, &lock);
        }

        if (task_available){
            printf("Thread %d handling task %d.\n", thread_id, tasks_handled);
            tasks_handled++;
            sleep(1);
            task_available = 0;
        }

        pthread_mutex_unlock(&lock);

        if (tasks_handled == THREAD_COUNT){
            break;
        }
    }

    printf("Worker Thread %d exiting.\n", thread_id);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[THREAD_COUNT];
    int i;

    // initialize mutex and condition variable
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond_var, NULL);

    task_available = 0;
    tasks_handled = 0;

    // create worker threads
    for (i = 0; i < THREAD_COUNT; i++){
        pthread_create(&threads[i], NULL, worker_thread, (void*)i);
    }

    // main thread generates tasks
    for (i = 0; i < THREAD_COUNT; i++){
        sleep(1);
        printf("Generating task %d...\n", i);
        pthread_mutex_lock(&lock);
        task_available = 1;
        pthread_cond_signal(&cond_var);
        pthread_mutex_unlock(&lock);
    }

    // join worker threads
    for (i = 0; i < THREAD_COUNT; i++){
        pthread_join(threads[i], NULL);
    }

    // clean up
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond_var);

    return 0;
}