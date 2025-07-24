//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;

void *thread_function(void *arg) {
    pthread_mutex_lock(&lock); // Lock mutex
    char *message = (char *) arg; // Cast argument to string pointer
    for (int i = 0; i < 5; i++) { // Execute loop five times
        printf("%s\n", message); // Print message
        sleep(1); // Sleep for one second
    }
    pthread_mutex_unlock(&lock); // Unlock mutex
}

int main() {
    pthread_t thread1, thread2; // Define two thread IDs

    pthread_mutex_init(&lock, NULL); // Initialize mutex

    char *message1 = "Hello from thread 1"; // Define thread 1 message
    pthread_create(&thread1, NULL, thread_function, (void *) message1); // Create thread 1

    char *message2 = "Hello from thread 2"; // Define thread 2 message
    pthread_create(&thread2, NULL, thread_function, (void *) message2); // Create thread 2

    pthread_join(thread1, NULL); // Wait for thread 1 to finish
    pthread_join(thread2, NULL); // Wait for thread 2 to finish

    pthread_mutex_destroy(&lock); // Destroy mutex

    return 0; // Return success
}