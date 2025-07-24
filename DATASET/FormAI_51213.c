//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads
#define NUM_THREADS 5

// Define a structure to hold the thread arguments
typedef struct {
    int thread_id;
    char *message;
} thread_args;

void *print_message(void *arg) {
    thread_args *ta = (thread_args *)arg;
    printf("Thread %d: %s\n", ta->thread_id, ta->message);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_args args[NUM_THREADS];

    int rc, t;
    void *status;

    char *messages[NUM_THREADS] = {
        "Hello",
        "Bonjour",
        "Hola",
        "Ciao",
        "Konnichiwa"
    };

    for (t = 0; t < NUM_THREADS; t++) {
        args[t].thread_id = t;
        args[t].message = messages[t];
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, print_message, (void *)&args[t]);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], &status);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Completed join with thread %d\n", t);
    }

    pthread_exit(NULL);
}