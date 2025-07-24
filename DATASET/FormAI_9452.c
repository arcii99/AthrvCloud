//FormAI DATASET v1.0 Category: Arithmetic ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_barrier_t barrier; // initialize pthread_barrier_t variable


void *addition(void *arg) {
    int *data = (int *) arg;

    // wait for all threads to start
    pthread_barrier_wait(&barrier);

    int result = 0;
    for(int i = 0; i < 10; i++) {
        result += data[i];
    }
    
    printf("Sum of numbers: %d\n", result);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id;
    pthread_barrier_init(&barrier, NULL, 1); // set to 1 thread
    
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pthread_create(&thread_id, NULL, &addition, (void*)numbers);

    pthread_join(thread_id, NULL);
    pthread_barrier_destroy(&barrier);
    
    return 0;
}