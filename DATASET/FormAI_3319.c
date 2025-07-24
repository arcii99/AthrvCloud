//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5
#define CRYPTIC_CONSTANT 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int shared_counter = 0;

void* thread_function(void* thread_id) {
    int id = *(int*) thread_id;
    
    pthread_mutex_lock(&mutex);
    shared_counter += id*CRYPTIC_CONSTANT;
    printf("Thread %d updated shared counter to %d\n", id, shared_counter);
    pthread_mutex_unlock(&mutex);
    
    sleep(1);
    
    pthread_mutex_lock(&mutex);
    shared_counter -= id*CRYPTIC_CONSTANT;
    printf("Thread %d decreased shared counter to %d\n", id, shared_counter);
    pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    printf("Starting Cryptic Example Program\n");
    
    for(int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i+1;
        printf("Creating Thread #%d\n", i+1);
        pthread_create(&threads[i], NULL, thread_function, (void*) &thread_ids[i]);
    }
    
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Final shared counter value: %d\n", shared_counter);
    printf("Ending Cryptic Example Program\n");
    
    return 0;
}