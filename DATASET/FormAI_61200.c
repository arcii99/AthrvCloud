//FormAI DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventName) {
    // Get the current time
    time_t currentTime;
    time(&currentTime);
    char* timeString = ctime(&currentTime);

    // Open the log file
    FILE* logFile = fopen("system.log", "a");

    // Write the event to the log file
    fprintf(logFile, "%s: %s\n", timeString, eventName);

    // Close the log file
    fclose(logFile);
}

int main() {
    printf("Hello! I'm a unique C System event logger!\n");

    // Ask the user for an event name
    char eventName[50];
    printf("What event should I log? ");
    scanf("%s", eventName);

    // Log the event
    logEvent(eventName);

    // Let the user know the event was logged
    printf("Event logged!\n");

    return 0;
}