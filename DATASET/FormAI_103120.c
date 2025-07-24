//FormAI DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Event {
    char description[100];
    char timestamp[20];
} Event;

void logEvent(char *description)
{
    FILE *fptr;
    Event event;

    // get timestamp
    time_t rawtime;
    struct tm *info;
    char timestamp[20];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", info);

    // create event
    strcpy(event.timestamp, timestamp);
    strcpy(event.description, description);

    // write to file
    fptr = fopen("system.log", "a+");
    if (fptr == NULL) {
        printf("File could not be opened.\n");
        exit(1);
    } else {
        fprintf(fptr, "%s - %s\n", event.timestamp, event.description);
        fclose(fptr);
    }
}

int main()
{
    char description[100];

    printf("Welcome to the system event logger!\n");

    while (1) {
        printf("Please enter a description of the event (or 'q' to quit):\n");
        scanf("%[^\n]%*c", description);

        if (strcmp(description, "q") == 0) {
            printf("Thank you for using the system event logger!\n");
            break;
        }

        logEvent(description);
        printf("Event logged.\n");
    }

    return 0;
}