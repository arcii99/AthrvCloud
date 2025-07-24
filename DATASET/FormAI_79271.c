//FormAI DATASET v1.0 Category: System event logger ; Style: Claude Shannon
#include <stdio.h>
#include <time.h>

int main() {
    FILE *logger;
    char event[100];
    time_t currentTime;

    // Open the event logger file in append mode
    logger = fopen("system_event.log", "a");

    if (logger == NULL) {
        printf("Error: Could not open event logger file!\n");
        return 1;
    }

    // Get the current time
    time(&currentTime);

    // Prompt the user for the event description
    printf("Enter the description of the event: ");
    fgets(event, 100, stdin);

    // Write the event to the log along with the timestamp
    fprintf(logger, "%s:%s", ctime(&currentTime), event);

    // Close the logger file
    fclose(logger);

    return 0;
}