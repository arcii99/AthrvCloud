//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

void *run_thread(void *thread_number) {
    printf("Thread %d running\n", *(int*)thread_number);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    
    for (int i=0; i<MAX_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, run_thread, &thread_ids[i]);
    }
    
    for (int i=0; i<MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads have completed\n");
    
    return 0;
}