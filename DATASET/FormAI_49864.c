//FormAI DATASET v1.0 Category: System event logger ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Struct to hold event information */
typedef struct Event {
    char* type;
    char* message;
    time_t timestamp;
} Event;

/* Function to print an event to the console */
void printEvent(Event event) {
    printf("%s: %s (%s)", event.type, event.message, ctime(&event.timestamp));
}

/* Function to log an event */
void logEvent(char* type, char* message) {
    /* Create a new event */
    Event event;
    event.type = type;
    event.message = message;
    event.timestamp = time(NULL);
    
    /* Print the event */
    printEvent(event);
    
    /* Write the event to a log file */
    FILE* file;
    file = fopen("events.log", "a");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(file, "%s: %s (%s)", event.type, event.message, ctime(&event.timestamp));
    fclose(file);
}

int main() {
    logEvent("System", "Program started");
    
    /* Code here */
    
    logEvent("System", "Program stopped");
    return 0;
}