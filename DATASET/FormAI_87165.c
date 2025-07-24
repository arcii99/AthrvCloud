//FormAI DATASET v1.0 Category: System event logger ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 5 // maximum number of threads
#define MAX_EVENTS 1000 // maximum number of events to be logged

// Mutex variables
pthread_mutex_t mutex;
pthread_cond_t event_available;

// Struct for logging event data
typedef struct {
    char message[100];
    int thread_id;
} event_data;

// Global variables
int num_events = 0;
event_data events[MAX_EVENTS];

// Function to log event data
void log_event(char* message, int thread_id) {
    pthread_mutex_lock(&mutex);

    while (num_events == MAX_EVENTS) {
        pthread_cond_wait(&event_available, &mutex);
    }

    strcpy(events[num_events].message, message);
    events[num_events].thread_id = thread_id;
    num_events++;

    pthread_cond_signal(&event_available);
    pthread_mutex_unlock(&mutex);
}

// Function to be run by threads
void* thread_func(void* thread_id) {
    int id = *(int*) thread_id;

    // Simulating logging events
    for (int i = 0; i < 200; i++) {
        char message[100];
        sprintf(message, "Thread %d logged event %d", id, i);
        log_event(message, id);
    }

    return NULL;
}

// Main function
int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    // Initializing mutex and condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&event_available, NULL);

    // Starting threads
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    // Joining threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Printing all logged events
    for (int i = 0; i < num_events; i++) {
        printf("Thread %d logged: %s\n", events[i].thread_id, events[i].message);
    }

    // Destroying mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&event_available);

    return 0;
}