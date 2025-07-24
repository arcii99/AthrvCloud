//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Shape-shifting C Threading Library Implementation Example */

/* Define a structure to hold thread ID and message */
typedef struct {
    pthread_t thread_id;
    char *message;
} thread_data;

/* Define the thread function to print the message */
void *print_message(void *data) {
    thread_data *thread = (thread_data *)data;
    printf("Message from thread #%ld: %s\n", thread->thread_id, thread->message);
    pthread_exit(NULL);
}

int main() {
    /* Declare an array to hold 3 thread structures */
    thread_data threads[3];

    /* Set up the messages for each thread */
    char *messages[] = {"Hello from Thread 1!", "Bonjour from Thread 2!", "Hola from Thread 3!"};

    /* Create the threads and assign each a message */
    for (int i = 0; i < 3; i++) {
        threads[i].message = messages[i];
        pthread_create(&(threads[i].thread_id), NULL, &print_message, (void *)&threads[i]);
    }

    /* Wait for the threads to finish */
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i].thread_id, NULL);
    }

    return 0;
}