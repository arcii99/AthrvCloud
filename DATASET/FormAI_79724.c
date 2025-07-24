//FormAI DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define EVENT_LOG_FILE "eventlog.txt"
#define MAX_EVENT_DESCRIPTION_LENGTH 100

// event log struct definition
typedef struct {
    time_t time;
    char description[MAX_EVENT_DESCRIPTION_LENGTH];
} EventLog;

// function to add event to log file
void addEventLog(EventLog event) {
    FILE *file = fopen(EVENT_LOG_FILE, "a");
    fprintf(file, "%s - %s\n", ctime(&event.time), event.description);
    fclose(file);
}

int main(void) {
    printf("Welcome to the System Event Logger!\n");
    printf("Please enter the details of the event:\n");

    // get event details from user
    char description[MAX_EVENT_DESCRIPTION_LENGTH];
    printf("Description (max %d characters): ", MAX_EVENT_DESCRIPTION_LENGTH-1);
    fgets(description, MAX_EVENT_DESCRIPTION_LENGTH, stdin);
    description[strcspn(description, "\n")] = '\0'; // remove newline at end

    // create event log struct
    EventLog event;
    event.time = time(NULL);
    strcpy(event.description, description);

    // add event to log file
    addEventLog(event);

    printf("Event logged successfully!\n");

    return 0;
}