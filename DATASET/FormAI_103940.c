//FormAI DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE_NAME "events.txt"
#define MAX_LOG_LENGTH 100

typedef struct {
    char event_time[20];
    char event_message[MAX_LOG_LENGTH];
} EventLog;

void log_event(char* message) {
    EventLog event;
    strcpy(event.event_message, message);
    
    // Get current time
    time_t current_time = time(NULL);
    struct tm* time_info = localtime(&current_time);
    strftime(event.event_time, 20, "%Y-%m-%d %H:%M:%S", time_info);
    
    // Open log file for appending
    FILE* log_file = fopen(LOG_FILE_NAME, "a");
    if (log_file == NULL) {
        printf("Error: Unable to open log file!\n");
        exit(EXIT_FAILURE);
    }
    
    // Write log entry to file
    fprintf(log_file, "%s - %s\n", event.event_time, event.event_message);
    
    // Close log file
    fclose(log_file);
}

int main() {
    // Test log_event function
    log_event("Program started.");
    log_event("User logged in.");
    log_event("Database connection established.");
    log_event("Data processed successfully.");
    log_event("Program terminated.");
    
    return 0;
}