//FormAI DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    time_t timestamp;
    char event_type[50];
    char event_message[100];
} Event;

int main(){
    Event event;
    time_t current_time;

    // Get the current time for timestamp
    current_time = time(NULL);

    // Set the event type and message
    strcpy(event.event_type, "System");
    strcpy(event.event_message, "An error occurred in the system");

    // Log the event to file
    FILE *fileptr;
    fileptr = fopen("system_log.txt", "a");

    // Check if file was opened successfully
    if (fileptr == NULL) {
        printf("Error opening log file");
        exit(1);
    }

    // Write the event details to file
    fprintf(fileptr, "[ %s ] [ %s ] [ %s ]\n", asctime(localtime(&current_time)), event.event_type, event.event_message);

    // Close the log file
    fclose(fileptr);

    // Print a success message to confirm log was written
    printf("Event logged successfully");

    return 0;
}