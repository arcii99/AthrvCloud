//FormAI DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_LOG_FILE "event_log.txt"

// Struct for holding event log data
typedef struct {
    time_t timestamp;
    char event[50];
} EventLog;

int main() {
    // Open Event Log File
    FILE *fptr = fopen(EVENT_LOG_FILE, "a");
    if(fptr == NULL) {
        printf("Failed to open event log file!\n");
        return 1;
    }

    // Get current time
    time_t current_time;
    time(&current_time);
    char* timestamp_string = ctime(&current_time);
    timestamp_string[strlen(timestamp_string) - 1] = '\0'; // remove newline character

    // Create Event Log object with current time and event message
    EventLog new_event_log;
    new_event_log.timestamp = current_time;
    strcpy(new_event_log.event, "System started up successfully");

    // Write event log object to file
    fprintf(fptr, "[%s] %s\n", timestamp_string, new_event_log.event);

    // Close file
    fclose(fptr);

    return 0;
}