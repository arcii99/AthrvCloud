//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct thread_data_t {
    int thread_id;
    char message[100];
} thread_data_t;

pthread_t threads[NUM_THREADS];
thread_data_t thread_data[NUM_THREADS];

void *print_message(void *thread_arg) {
    thread_data_t *data;
    data = (thread_data_t *) thread_arg;
    
    printf("Thread %d says: %s\n", data->thread_id, data->message);
    
    pthread_exit(NULL);
}

int main() {
    int i;
    
    for (i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        sprintf(thread_data[i].message, "Hello from thread %d", i);
        
        pthread_create(&threads[i], NULL, print_message, (void *) &thread_data[i]);
    }
    
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}