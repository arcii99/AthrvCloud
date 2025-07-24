//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 4
#define SIZE 100

int arr[SIZE];

typedef struct {
    int start_index;
    int end_index;
    int target;
    int result;
} ThreadArgs;

void* search(void* args) {
    ThreadArgs* thread_args = (ThreadArgs*) args;
    int start_index = thread_args->start_index;
    int end_index = thread_args->end_index;
    int target = thread_args->target;
    
    for (int i = start_index; i < end_index; i++) {
        if (arr[i] == target) {
            thread_args->result = i;
            return NULL;
        }
    }
    
    return NULL;
}

int main() {
    srand(time(NULL));
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand()%1000;
    }
    
    int target = arr[rand() % SIZE];
    
    pthread_t threads[THREADS];
    ThreadArgs thread_args[THREADS];
    
    int chunk_size = SIZE / THREADS;
    
    for (int i = 0; i < THREADS; i++) {
        thread_args[i].start_index = i*chunk_size;
        thread_args[i].end_index = (i+1)*chunk_size;
        thread_args[i].target = target;
        thread_args[i].result = -1;
        
        pthread_create(&threads[i], NULL, search, (void*)&thread_args[i]);
    }
    
    int result = -1;
    
    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
        if (thread_args[i].result != -1) {
            result = thread_args[i].result;
        }
    }
    
    printf("Target: %d\n", target);
    printf("Result: %d\n", result);
    
    return 0;
}