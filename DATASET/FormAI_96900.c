//FormAI DATASET v1.0 Category: System event logger ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_EVENTS 1000

// Global variables
pthread_mutex_t lock;
int event_count = 0;

// Struct to store event details
typedef struct {
    int event_id;
    char* event_type;
    char* event_description;
} Event;

// Function to log an event
void log_event(char* type, char* description) {
    pthread_mutex_lock(&lock); // Acquire lock before performing write operation
    
    Event ev;
    ev.event_id = event_count + 1;
    ev.event_type = type;
    ev.event_description = description;
    
    // Write event details to log file
    FILE* log_file = fopen("event_log.txt", "a");
    if (log_file != NULL) {
        fprintf(log_file, "Event ID: %d, Type: %s, Description: %s\n", ev.event_id, ev.event_type, ev.event_description);
        fclose(log_file);
    }
    
    event_count++;
    
    pthread_mutex_unlock(&lock); // Release lock after write operation
}

// Thread function to simulate event logging
void* log_events(void* arg) {
    char* event_types[] = {"WARNING", "ERROR", "INFO", "DEBUG"};
    char* event_descriptions[] = {"Disk space running low", "Connection timed out", "New user registered", "API request received"};
    
    for (int i = 0; i < 10; i++) {
        int type_index = rand() % 4;
        int desc_index = rand() % 4;
        
        log_event(event_types[type_index], event_descriptions[desc_index]);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);
    
    // Create multiple threads to simulate event logging
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, log_events, NULL);
    }
    
    // Wait for all threads to finish execution
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Destroy mutex
    pthread_mutex_destroy(&lock);
    
    // Print total number of events logged
    printf("Total number of events logged: %d\n", event_count);
    
    return 0;
}