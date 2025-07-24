//FormAI DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <time.h>

void logEvent(char* event) {
    FILE *fp;
    time_t timestamp;
    char line[100];

    // Get current time
    time(&timestamp);

    // Open file for appending
    fp = fopen("events.log", "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Format log line with timestamp and event
    sprintf(line, "[%s] %s\n", asctime(localtime(&timestamp)), event);

    // Write log line to file
    fputs(line, fp);

    // Close file
    fclose(fp);
}

int main() {
    char event[50];

    // Get event from user input
    printf("Enter event: ");
    fgets(event, sizeof(event), stdin);

    // Log event
    logEvent(event);

    return 0;
}