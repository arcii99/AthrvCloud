//FormAI DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define the log struct
typedef struct {
    time_t timestamp;
    char* event_type;
    char* message;
} Log;

// A function to log an event
void log_event(char* event_type, char* message) {
    // Create a new log entry
    Log new_log;
    new_log.timestamp = time(NULL);
    new_log.event_type = event_type;
    new_log.message = message;
    // Open the log file
    FILE* log_file = fopen("system_events.log", "a");
    if (log_file == NULL) {
        printf("Unable to open log file.\n");
        exit(1);
    }
    // Write the log entry to the file
    fprintf(log_file, "[%s] [%s] %s\n", asctime(localtime(&new_log.timestamp)), new_log.event_type, new_log.message);
    // Close the log file
    fclose(log_file);
}

int main() {
    // Log some events
    log_event("INFO", "System startup.");
    log_event("WARNING", "File system full.");
    log_event("ERROR", "Unable to connect to network.");
    return 0;
}