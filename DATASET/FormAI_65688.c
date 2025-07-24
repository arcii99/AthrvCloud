//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a global variable for the threads to work with
int global_var = 0;

// Define a thread function which increments global_var 1000000 times
void* thread_function(void* arg) {
    for(int i = 0; i < 1000000; i++) {
        global_var++;
    }
    return NULL;
}

// Define the main function which creates two threads and waits for them to finish
int main() {
    // Create the first thread
    pthread_t thread1;
    if(pthread_create(&thread1, NULL, thread_function, NULL)) {
        fprintf(stderr, "Error creating thread1!\n");
        return 1;
    }

    // Create the second thread
    pthread_t thread2;
    if(pthread_create(&thread2, NULL, thread_function, NULL)) {
        fprintf(stderr, "Error creating thread2!\n");
        return 1;
    }

    // Wait for the first thread to finish
    if(pthread_join(thread1, NULL)) {
        fprintf(stderr, "Error joining thread1!\n");
        return 2;
    }

    // Wait for the second thread to finish
    if(pthread_join(thread2, NULL)) {
        fprintf(stderr, "Error joining thread2!\n");
        return 2;
    }

    // Print the final value of global_var
    printf("The value of global_var is %d\n", global_var);

    return 0;
}