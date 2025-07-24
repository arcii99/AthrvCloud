//FormAI DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventType, char* message);

int main() {
    char eventType[20];
    char message[200];

    printf("Enter event type: ");
    scanf("%s", eventType);

    printf("Enter message: ");
    scanf(" %[^\n]s", message);

    logEvent(eventType, message);

    printf("Event logged successfully.");

    return 0;
}

void logEvent(char* eventType, char* message) {
    time_t now;
    struct tm *local;
    char filename[50];

    now = time(NULL);
    local = localtime(&now);

    sprintf(filename, "%d-%d-%d.log", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday);

    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    fprintf(file, "[%02d:%02d:%02d] Event Type: %s, Message: %s\n", local->tm_hour, local->tm_min, local->tm_sec, eventType, message);
    fclose(file);
}