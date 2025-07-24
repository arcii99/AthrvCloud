//FormAI DATASET v1.0 Category: System event logger ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *eventType, char *description);

int main() {
    char eventType[20];
    char description[100];

    printf("Enter event type: ");
    scanf("%s", eventType);

    printf("Enter description: ");
    scanf(" %[^\n]s", description);

    logEvent(eventType, description);
    return 0;
}

void logEvent(char *eventType, char *description) {
    FILE *file_pointer;
    time_t current_time;
    char *time_string;

    current_time = time(NULL);
    time_string = ctime(&current_time);

    file_pointer = fopen("event.log", "a");
    if (file_pointer == NULL) {
        printf("Error! Could not create/open log file.");
        exit(1);
    }

    fprintf(file_pointer, "[%s] %s: %s\n", time_string, eventType, description);

    printf("Event successfully logged!\n");
    fclose(file_pointer);
}