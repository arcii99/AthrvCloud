//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10

pthread_mutex_t mutex;
pthread_cond_t cond_var;

int num_threads = 0;

void* thread_function(void* arg)
{
    int id = *(int*) arg;
    
    while (num_threads > 1) {
        pthread_mutex_lock(&mutex);
        
        while (num_threads % 2 == 1) {
            pthread_cond_wait(&cond_var, &mutex);
        }
        
        if (id == num_threads) {
            printf("Thread %d is locking the mutex\n", id);
            pthread_mutex_unlock(&mutex);
            sleep(2);
            printf("Thread %d has released the mutex\n", id);
        } else {
            pthread_mutex_unlock(&mutex);
        }
        
        pthread_mutex_lock(&mutex);
        num_threads--;
        
        pthread_cond_broadcast(&cond_var);
        pthread_mutex_unlock(&mutex);
    }
    
    printf("Thread %d has finished\n", id);
    
    return NULL;
}

int main()
{
    pthread_t threads[MAX_THREADS];
    int thread_params[MAX_THREADS];
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_var, NULL);
    
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_params[i] = i + 1;
        
        if (pthread_create(&threads[i], NULL, &thread_function, &thread_params[i])) {
            printf("Could not create thread %d\n", i);
            return -1;
        }
        
        num_threads++;
        sleep(1);
    }
    
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Could not join thread %d\n", i);
            return -1;
        }
    }
    
    printf("All threads have completed successfully\n");
    
    return 0;
}