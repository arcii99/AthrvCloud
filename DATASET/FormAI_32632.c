//FormAI DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <time.h>

/* Struct for storing event data */
typedef struct Event {
    char* description;
    time_t time;
} Event;

/* Function to log an event */
void logEvent(char* description, Event* events, int* numEvents) {
    time_t currentTime = time(NULL);
    events[*numEvents].description = description;
    events[*numEvents].time = currentTime;
    (*numEvents)++;
    printf("Event Logged!\n");
}

/* Function to print all logged events */
void printEvents(Event* events, int numEvents) {
    printf("Logged Events:\n");
    for(int i = 0; i < numEvents; i++) {
        printf("Time: %sDescription: %s\n", asctime(localtime(&events[i].time)), events[i].description);
    }
}

int main() {
    /* Initialize event log */
    Event events[100];
    int numEvents = 0;

    /* Start logging events */
    logEvent("The King has been crowned!", events, &numEvents);
    logEvent("The Queen has given birth to a princess!", events, &numEvents);
    logEvent("A great feast has been held in honor of the royal family!", events, &numEvents);
    logEvent("The black plague has hit our kingdom!", events, &numEvents);

    /* Print the logged events */
    printEvents(events, numEvents);

    return 0;
}