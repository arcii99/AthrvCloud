//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 1000000
#define MAX_THREADS 4
#define RANGE 1000

int array[ARRAY_SIZE];
int sorted_array[ARRAY_SIZE];
int bucket_count[RANGE];
pthread_mutex_t lock;

void *sort(void* arg) {
    int thread_id = *(int*)arg;
    int start = (ARRAY_SIZE/MAX_THREADS) * thread_id;
    int end = start + (ARRAY_SIZE/MAX_THREADS);
    
    for (int i = start; i < end; i++) {
        pthread_mutex_lock(&lock);
        bucket_count[array[i]]++;
        pthread_mutex_unlock(&lock);
    }
    
    pthread_exit(NULL);
}

void *combine() {
    int sorted_index = 0;
    for (int i = 0; i < RANGE; i++) {
        for (int j = 0; j < bucket_count[i]; j++) {
            sorted_array[sorted_index++] = i;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread[MAX_THREADS];
    int thread_id[MAX_THREADS];
    pthread_mutex_init(&lock, NULL);
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % RANGE;
    }
    
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_id[i] = i;
        pthread_create(&thread[i], NULL, sort, &thread_id[i]);
    }
    
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(thread[i], NULL);
    }
    
    pthread_t combine_thread;
    pthread_create(&combine_thread, NULL, combine, NULL);
    
    pthread_join(combine_thread, NULL);
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", sorted_array[i]);
    }
    
    pthread_mutex_destroy(&lock);
    return 0;
}