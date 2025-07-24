//FormAI DATASET v1.0 Category: System event logger ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void logEvent(char* eventType, char* description);

int main() {
    char eventType[20], description[100];
    printf("Welcome to the System Event Logger!\n");

    while (1) {
        printf("\nPlease enter the event type: ");
        fgets(eventType, 20, stdin);
        eventType[strcspn(eventType, "\n")] = 0; // Remove newline character from input

        printf("\nPlease enter a short description of the event: ");
        fgets(description, 100, stdin);
        description[strcspn(description, "\n")] = 0;

        logEvent(eventType, description);

        printf("\nEvent logged!\n");
    }

    return 0;
}

void logEvent(char* eventType, char* description) {
    time_t t;
    struct tm* timestamp;
    char logMsg[150];

    // Get current time
    time(&t);
    timestamp = localtime(&t);

    // Create log message
    sprintf(logMsg, "[%02d/%02d/%04d %02d:%02d:%02d] %s: %s\n", 
            timestamp->tm_mday, timestamp->tm_mon + 1, timestamp->tm_year + 1900, 
            timestamp->tm_hour, timestamp->tm_min, timestamp->tm_sec, eventType, description);

    // Open log file in append mode and write log message
    FILE* logFile = fopen("system_events.log", "a");
    fprintf(logFile, "%s", logMsg);
    fclose(logFile);
}