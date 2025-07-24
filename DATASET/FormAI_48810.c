//FormAI DATASET v1.0 Category: Scientific ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define THREADS_NUM 5

void *print_thread_id(void *thread_id) {
    int id = *(int *)thread_id;
    printf("Thread %d is starting...\n", id);
    printf("Thread %d is running...\n", id);
    
    for(int i=0; i<5; i++) {
        printf("Thread %d is executing iteration %d...\n", id, i+1);
        sleep(1);
    }
    
    printf("Thread %d is exiting...\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS_NUM];
    int thread_ids[THREADS_NUM];
    
    for(int i=0; i<THREADS_NUM; i++) {
        printf("Creating thread %d...\n", i+1);
        thread_ids[i] = i+1;
        pthread_create(&threads[i], NULL, print_thread_id, (void *)&thread_ids[i]);
    }
    
    printf("Main thread is waiting for other threads to finish...\n");
    
    for(int i=0; i<THREADS_NUM; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads have finished. Exiting main thread...\n");
    pthread_exit(NULL);
}