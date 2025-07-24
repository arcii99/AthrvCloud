//FormAI DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void logEvent(char* eventName);

// main function
int main() {
    // list of potential events to log
    char* events[5] = {"system start", "file created", "file deleted", "application error", "system shutdown"};

    // initialize random seed
    srand(time(NULL));

    // log 10 random events
    for(int i = 0; i < 10; i++) {
        // generate a random index
        int index = rand() % 5;

        // get the event name
        char* eventName = events[index];

        // log the event
        logEvent(eventName);
    }

    return 0;
}

// function to log an event
void logEvent(char* eventName) {
    // get the current time
    time_t now = time(NULL);
    char* timeString = ctime(&now);

    // log the event
    printf("EVENT LOGGED: %s at %s", eventName, timeString);
}