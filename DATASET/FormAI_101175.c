//FormAI DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct event { // Define structure for the event log
    char timestamp[20];
    char event_type[50];
    char description[200];
};

void log_event(struct event new_event) {
    FILE *fp;
    fp = fopen("event_log.txt", "a"); // Open file in Append mode
    
    if (fp == NULL) { // Check if file opened successfully
        printf("Error opening file!\n");
        exit(1);
    }
    
    fprintf(fp, "[%s] %s: %s\n", new_event.timestamp, new_event.event_type, new_event.description);
    fclose(fp);
}

int main() {
    struct event new_event;
    time_t current_time;
    char timestamp[20];
    
    current_time = time(NULL); // Get current time
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&current_time)); // Format time as string
    
    strcpy(new_event.timestamp, timestamp);
    strcpy(new_event.event_type, "System Error");
    strcpy(new_event.description, "Fatal error occurred, system shutting down."); // Populate event details
    
    log_event(new_event); // Call log_event function to log the event
    
    return 0;
}