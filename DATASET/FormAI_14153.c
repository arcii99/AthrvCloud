//FormAI DATASET v1.0 Category: System event logger ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define EVENTS_FILE "events.log"

typedef struct {
    char event[50];
    char timestamp[25];
} LogEvent;

int main() {
    FILE* eventsFile = fopen(EVENTS_FILE, "a");
    if (eventsFile == NULL) {
        printf("Error opening events file.");
        return 1;
    }

    int numEvents;
    printf("Enter the number of events: ");
    scanf("%d", &numEvents);

    LogEvent* events = malloc(sizeof(LogEvent) * numEvents);

    for(int i = 0; i < numEvents; i++) {
        printf("Enter event %d: ", i+1);
        scanf("%s", events[i].event);

        time_t rawTime;
        time(&rawTime);
        struct tm* currentTime = localtime(&rawTime);
        sprintf(events[i].timestamp, "%04d-%02d-%02d %02d:%02d:%02d",
            currentTime->tm_year + 1900, currentTime->tm_mon + 1, currentTime->tm_mday,
            currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);
    }

    for(int i = 0; i < numEvents; i++) {
        fprintf(eventsFile, "%s %s\n", events[i].timestamp, events[i].event);
    }

    fclose(eventsFile);
    free(events);

    printf("Events saved to %s", EVENTS_FILE);
    return 0;
}