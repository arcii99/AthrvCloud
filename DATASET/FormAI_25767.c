//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

void *print_message(void *thread_num) {
    int num = *(int*)thread_num;
    printf("Hello from thread %d\n", num);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    
    int thread_args[NUM_THREADS];
    int i;
    
    //create threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, print_message, (void *)&thread_args[i]);
    }
    
    // wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads have completed\n");
    return 0;
}