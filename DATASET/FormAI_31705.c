//FormAI DATASET v1.0 Category: System event logger ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventType, char* eventMessage) {
    time_t eventTime;
    time(&eventTime);
    FILE *logFile = fopen("eventlog.txt", "a");
    fprintf(logFile, "%s - %s: %s\n", asctime(localtime(&eventTime)), eventType, eventMessage);
    fclose(logFile);
}

int main() {
    char eventType[100], eventMessage[200];
    printf("Enter the type of event: ");
    scanf("%s", eventType);
    printf("Enter the event message: ");
    scanf("%s", eventMessage);
    logEvent(eventType, eventMessage);
    printf("Event logged successfully");
    return 0;
}