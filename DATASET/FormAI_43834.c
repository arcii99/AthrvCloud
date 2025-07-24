//FormAI DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_EVENTS 1000
#define MAX_EVENT_NAME_LENGTH 50
#define MAX_LOG_FILE_NAME_LENGTH 100

// Define structs
typedef struct {
    char name[MAX_EVENT_NAME_LENGTH];
    time_t timestamp;
} Event;

typedef struct {
    Event events[MAX_EVENTS];
    int count;
} EventLog;

// Function declarations
void logEvent(EventLog *log, const char *name, const time_t timestamp);
void displayLog(EventLog *log);
void saveLog(EventLog *log, const char *fileName);

int main() {
    EventLog log = { .count = 0 };  // Initialize log
    
    logEvent(&log, "Event 1", time(NULL));  // Log some events
    logEvent(&log, "Event 2", time(NULL));
    logEvent(&log, "Event 3", time(NULL));
    
    displayLog(&log);  // Display log on console
    
    saveLog(&log, "example.log");  // Save log to file
    
    return 0;
}

// Log a new event to the event log
void logEvent(EventLog *log, const char *name, const time_t timestamp) {
    // Check if event log is full
    if (log->count >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.");
        return;
    }
    
    // Create new event and add to log
    Event newEvent;
    strncpy(newEvent.name, name, MAX_EVENT_NAME_LENGTH);
    newEvent.timestamp = timestamp;
    log->events[log->count] = newEvent;
    log->count++;
}

// Display the contents of the event log
void displayLog(EventLog *log) {
    printf("Event Log:\n");
    for (int i = 0; i < log->count; i++) {
        printf("%d. %s - %s", i + 1, log->events[i].name, ctime(&log->events[i].timestamp));
    }
}

// Save the event log to a file
void saveLog(EventLog *log, const char *fileName) {
    // Open file for writing
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'.", fileName);
        return;
    }
    
    // Write events to file
    for (int i = 0; i < log->count; i++) {
        fprintf(file, "%d. %s - %s", i + 1, log->events[i].name, ctime(&log->events[i].timestamp));
    }
    
    // Close file
    fclose(file);
}