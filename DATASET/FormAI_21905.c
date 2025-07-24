//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

struct thread_info {
    int index;
    char* message;
};

void* thread_function(void* arg) {
    struct thread_info* info = (struct thread_info*) arg;
    printf("Thread %d message: %s\n", info->index, info->message);
    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    struct thread_info thread_data[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        thread_data[i].index = i;
        thread_data[i].message = "Hello from thread!";
        pthread_create(&threads[i], NULL, thread_function, &thread_data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}