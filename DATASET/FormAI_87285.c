//FormAI DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
/* Event logger program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define a structure for each logged event */
typedef struct EventLog {
    char eventType[20];
    char eventDesc[100];
    time_t eventTime;
} EventLog;

/* Function to save the event to file */
void saveEvent(EventLog *event) {
    FILE *fp;
    fp = fopen("eventlog.txt", "a");
    fprintf(fp, "%s: %s [time: %s]", event->eventType, event->eventDesc, asctime(localtime(&event->eventTime)));
    fclose(fp);
}

int main() {
    /* Declare variables */
    EventLog event;
    time_t currentTime;

    /* Get current time */
    time(&currentTime);

    /* Set values for event */
    strcpy(event.eventType, "Error");
    strcpy(event.eventDesc, "Segmentation fault");
    event.eventTime = currentTime;

    /* Save event to file */
    saveEvent(&event);

    printf("Event logged successfully!");

    return 0;
}