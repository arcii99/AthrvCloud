//FormAI DATASET v1.0 Category: System event logger ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to log the system events
void systemEventLogger(char *event, char *description) {
    FILE *fp;
    time_t now;

    time(&now);

    fp = fopen("system_events.log", "a");

    if (fp == NULL) {
        printf("Failed to open system_events.log file.");
        return;
    }

    fprintf(fp, "\n%s%s %s%s %s", "Event:", event, "| Description:", description, ctime(&now));
    fclose(fp);
}

int main() {
    char event[50];
    char description[100];

    printf("Welcome to the System Event Logger.\n");
    printf("===================================\n");

    printf("\nEnter the event name: ");
    scanf("%49s", event);

    printf("Enter the description of the event: ");
    scanf("%99s", description);

    systemEventLogger(event, description);

    printf("\n\nEvent has been successfully logged!\n");

    return 0;
}