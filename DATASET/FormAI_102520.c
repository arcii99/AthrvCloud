//FormAI DATASET v1.0 Category: System event logger ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventType, char* eventMessage) {
    time_t now;
    time(&now);

    FILE* file = fopen("eventlog.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "Event Type: %s; Event Message: %s; Timestamp: %s", eventType, eventMessage, ctime(&now));
    fclose(file);

    printf("Event Logged Successfully!\n");
}

int main() {
    char eventType[50], eventMessage[100];

    printf("Enter the Event Type: ");
    fgets(eventType, 50, stdin);

    printf("Enter the Event Message: ");
    fgets(eventMessage, 100, stdin);

    logEvent(eventType, eventMessage);

    return 0;
}