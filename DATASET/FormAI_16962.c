//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//This is a thread function that simply prints a message indicating that it has started
void *thread_function(void *arg) {
    char *message = (char *)arg;
    printf("%s\n", message);
    pthread_exit(NULL); //exit thread
}

int main() {
    const int max_threads = 5;
    pthread_t threads[max_threads];
    int i;
    char message[20];

    //initialize the thread attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    //create multiple threads
    for (i = 0; i < max_threads; i++) {
        sprintf(message, "Thread %d", i);
        if (pthread_create(&threads[i], &attr, thread_function, message) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    //join the threads back together
    for (i = 0; i < max_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads completed\n");

    //clean up the attribute object
    pthread_attr_destroy(&attr);

    //exit the main thread
    pthread_exit(NULL);
}