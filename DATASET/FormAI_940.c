//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: excited
#include <stdio.h>
#include <pthread.h> // Include the threading library

// Function that prints "Hello" five times
void *printHello(void *arg) {
    int i;
    for(i=0;i<5;i++) {
        printf("Hello\n");
    }
    return NULL;
}

// Function that prints "World" five times
void *printWorld(void *arg) {
    int i;
    for(i=0;i<5;i++) {
        printf("World\n");
    }
    return NULL;
}

int main() {
    // Declare the two threads
    pthread_t thread1, thread2;

    // Create the first thread
    pthread_create(&thread1, NULL, &printHello, NULL);

    // Create the second thread
    pthread_create(&thread2, NULL, &printWorld, NULL);

    // Wait for the first thread to finish
    pthread_join(thread1, NULL);

    // Wait for the second thread to finish
    pthread_join(thread2, NULL);

    return 0;
}