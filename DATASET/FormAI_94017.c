//FormAI DATASET v1.0 Category: System event logger ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Event struct to hold information about system events
typedef struct {
    char event_name[50];
    time_t event_time;
} Event;

// Function to log events to file
void log_event(Event e) {
    FILE *fptr;
    fptr = fopen("system_events.log", "a");
    
    if(fptr == NULL) {
        printf("Error opening file.");
        return;
    }
    
    fprintf(fptr, "Event Name: %s\nEvent Time: %s\n", e.event_name, ctime(&(e.event_time)));
    fclose(fptr);
}

int main() {
    Event e;
    time(&(e.event_time)); // Set event time to current system time

    // Event 1: System startup
    sprintf(e.event_name, "System Startup");
    log_event(e);

    // Event 2: User Login
    sprintf(e.event_name, "User Login");
    log_event(e);

    // Event 3: Error Occurred
    sprintf(e.event_name, "Error Occurred");
    log_event(e);

    // Event 4: System Shutdown
    sprintf(e.event_name, "System Shutdown");
    log_event(e);

    return 0;
}