//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TERM 50 // maximum term in the Fibonacci sequence
#define DELAY 500000 // delay time for visualization

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // mutex lock for thread synchronisation
int term = 2; // current term in the sequence
unsigned long long seq[MAX_TERM]; // Fibonacci sequence array

void print_sequence(void) {
    printf("\nFibonacci sequence:\n\n");
    for (int i = 0; i < term; ++i) {
        printf("%llu ", seq[i]); // print each term in the sequence
    }
    printf("\n\n");
}

void *calculate_sequence(void *arg) {
    seq[0] = 0; // first term in the sequence
    seq[1] = 1; // second term in the sequence
    while (term < MAX_TERM) {
        // calculate next term in the sequence
        seq[term] = seq[term - 1] + seq[term - 2];
        pthread_mutex_lock(&lock); // acquire lock
        ++term; // increment current term
        pthread_mutex_unlock(&lock); // release lock
        usleep(DELAY); // wait for delay time
    }
    pthread_exit(NULL);
}

void *visualize_sequence(void *arg) {
    while (term < MAX_TERM) {
        pthread_mutex_lock(&lock); // acquire lock
        // visualize the current term
        printf("Term %d: ", term);
        for (unsigned long long i = 0; i < seq[term - 1]; ++i) {
            printf("*");
        }
        printf("\n");
        pthread_mutex_unlock(&lock); // release lock
        usleep(DELAY); // wait for delay time
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t calculate_thread, visualize_thread;
    int rc;

    // create threads for calculating and visualizing the sequence
    rc = pthread_create(&calculate_thread, NULL, calculate_sequence, NULL);
    if (rc) {
        fprintf(stderr, "Error creating calculate thread: %d\n", rc);
        exit(EXIT_FAILURE);
    }
    rc = pthread_create(&visualize_thread, NULL, visualize_sequence, NULL);
    if (rc) {
        fprintf(stderr, "Error creating visualize thread: %d\n", rc);
        exit(EXIT_FAILURE);
    }

    // main thread waits for the calculate and visualize threads to finish
    rc = pthread_join(calculate_thread, NULL);
    if (rc) {
        fprintf(stderr, "Error joining calculate thread: %d\n", rc);
        exit(EXIT_FAILURE);
    }
    rc = pthread_join(visualize_thread, NULL);
    if (rc) {
        fprintf(stderr, "Error joining visualize thread: %d\n", rc);
        exit(EXIT_FAILURE);
    }

    print_sequence(); // print the full Fibonacci sequence

    return 0;
}