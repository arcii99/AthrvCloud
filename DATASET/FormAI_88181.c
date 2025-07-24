//FormAI DATASET v1.0 Category: System event logger ; Style: automated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// A structure to represent system events
typedef struct {
    time_t timestamp;
    char* event;
} SystemEvent;

void logEvent(char* event) {
    // Get current timestamp
    time_t current_time = time(NULL);
    
    // Create new system event
    SystemEvent new_event;
    new_event.timestamp = current_time;
    new_event.event = event;
    
    // Open log file
    FILE* log_file = fopen("system.log", "a");
    
    // Write event to log file
    fprintf(log_file, "%s - %s\n", asctime(localtime(&new_event.timestamp)), new_event.event);
    
    // Close log file
    fclose(log_file);
}

int main() {
    // Log system events
    logEvent("System started");
    logEvent("User logged in");
    logEvent("File uploaded");
    
    return 0;
}