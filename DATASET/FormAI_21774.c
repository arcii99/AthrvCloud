//FormAI DATASET v1.0 Category: System event logger ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventType, char* eventDescription) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timestamp[50];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);

    FILE *f = fopen("event-log.txt", "a");
    if (f == NULL) {
        printf("Error opening event log file.\n");
        exit(1);
    }

    fprintf(f, "[%s] %s - %s\n", timestamp, eventType, eventDescription);

    fclose(f);
}

int main() {
    char eventType[20];
    char eventDescription[100];

    printf("Enter the event type: ");
    scanf("%[^\n]", eventType); // allows for spaces in input
    getchar(); // gets rid of newline character

    printf("Enter a brief event description: ");
    scanf("%[^\n]", eventDescription); // allows for spaces in input
    getchar(); // gets rid of newline character

    logEvent(eventType, eventDescription);

    printf("Event logged successfully.\n");

    return 0;
}