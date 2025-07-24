//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Defining a structure which will be passed as an argument to our thread function
struct thread_data {
    int thread_id;
    char message[20];
};

// Thread function which will be executed by each thread
void *print_message(void *arg) {
    struct thread_data *data;
    data = (struct thread_data *) arg; // Type casting the argument to our structure type
    
    printf("Thread ID: %d\nMessage: %s\n", data->thread_id, data->message);
    
    pthread_exit(NULL); // Terminating the thread
}

int main() {
    int num_threads = 5;
    pthread_t threads[num_threads];
    struct thread_data thread_data_array[num_threads];
    
    // Creating threads
    for (int i = 0; i < num_threads; i++) {
        printf("Creating thread number %d...\n", i+1);
        thread_data_array[i].thread_id = i+1;
        char message[20];
        sprintf(message, "Hello from thread %d", i+1);
        strcpy(thread_data_array[i].message, message);
        
        if (pthread_create(&threads[i], NULL, print_message, (void*) &thread_data_array[i])) {
            printf("Error creating thread!");
            exit(1);
        }
    }
    
    // Joining threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread!");
            exit(1);
        }
    }
    
    printf("All threads successfully executed!\n");
    
    pthread_exit(NULL); // Terminating the main thread
}