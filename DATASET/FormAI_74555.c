//FormAI DATASET v1.0 Category: System event logger ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This program implements an asynchronous system event logger which receives events from different sources and logs them to a file.
 * Each event contains a source identifier, a timestamp, and a message.
 */ 

// Structure to hold an event
typedef struct {
    int source_id;
    time_t timestamp;
    char message[100];
} Event;

// Function to log an event to a file
void log_event(Event event, FILE* file) {
    fprintf(file, "[%ld] Source %d: %s\n", event.timestamp, event.source_id, event.message);
}

// Function to generate a random event
Event generate_random_event(int source_id) {
    Event event;
    event.source_id = source_id;
    event.timestamp = time(NULL);
    sprintf(event.message, "Random message from source %d", source_id);
    return event;
}

// Function to periodically generate random events
void* generate_events_periodically(void* arg) {
    int source_id = *((int*) arg);
    FILE* file = fopen("events.log", "a");
    if (file == NULL) {
        printf("Error opening log file\n");
        return NULL;
    }
    for (int i = 0; i < 10; i++) {
        Event event = generate_random_event(source_id);
        log_event(event, file);
        sleep(rand() % 5);
    }
    fclose(file);
    return NULL;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create threads to generate events from different sources
    pthread_t thread1, thread2;
    int source_id1 = 1, source_id2 = 2;
    if (pthread_create(&thread1, NULL, generate_events_periodically, &source_id1) != 0) {
        printf("Error creating thread 1\n");
        return 1;
    }
    if (pthread_create(&thread2, NULL, generate_events_periodically, &source_id2) != 0) {
        printf("Error creating thread 2\n");
        return 1;
    }
    
    // Wait for threads to complete
    if (pthread_join(thread1, NULL) != 0) {
        printf("Error waiting for thread 1\n");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0) {
        printf("Error waiting for thread 2\n");
        return 1;
    }
    
    printf("Events generated and logged to events.log\n");
    return 0;
}