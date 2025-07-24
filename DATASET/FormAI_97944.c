//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

struct thread_data {
    int thread_id;
    char *message;
};

void *print_message(void *threadarg) {
    struct thread_data *thread_data;
    thread_data = (struct thread_data *)threadarg;

    printf("Thread %d says: %s\n", thread_data->thread_id, thread_data->message);
    pthread_exit(NULL);
}

int main () {
    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data_array[NUM_THREADS];
    char *messages[NUM_THREADS] = {"Hello", "World", "from", "threads!"};
    
    int i, rc;
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        thread_data_array[i].thread_id = i;
        thread_data_array[i].message = messages[i];
        rc = pthread_create(&threads[i], NULL, print_message, (void *)&thread_data_array[i]);

        if (rc) {
            printf("Error: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}