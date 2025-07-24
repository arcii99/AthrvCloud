//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: visionary
#include <stdio.h>
#include <pthread.h>

// A struct to pass multiple arguments to the thread function
struct args {
    int id;                 // Thread ID
    int num_iterations;     // Number of iterations for the thread to run
    int sleep_time;         // Sleep time in milliseconds
};

// Thread function
void *thread_function(void *arg) {
    struct args *args_ptr = (struct args*) arg;
    printf("Thread %d is starting.\n", args_ptr->id);
    
    for (int i = 0; i < args_ptr->num_iterations; i++) {
        printf("Thread %d iteration %d\n", args_ptr->id, i);
        usleep(args_ptr->sleep_time * 1000);   // Sleep for the given time
    }
    
    printf("Thread %d is exiting.\n", args_ptr->id);
    pthread_exit(NULL);
}

int main() {
    const int NUM_THREADS = 4;
    pthread_t threads[NUM_THREADS];
    struct args thread_args[NUM_THREADS];
    
    // Initialize and start the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].id = i;
        thread_args[i].num_iterations = 5;
        thread_args[i].sleep_time = 1000;   // Sleep for 1 second
        
        int rc = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            return 1;
        }
    }
    
    // Wait for all the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads finished.\n");
    return 0;
}