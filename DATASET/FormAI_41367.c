//FormAI DATASET v1.0 Category: System event logger ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventName, char* eventDescription) {
    FILE* fptr;

    fptr = fopen("event_log.txt", "a+");

    if (fptr == NULL) {
        printf("Error opening event log file!");
        return;
    }

    time_t currentTime;
    time(&currentTime);

    struct tm* localTime;
    localTime = localtime(&currentTime);

    fprintf(fptr, "Event Name: %s\n", eventName);
    fprintf(fptr, "Event Description: %s\n", eventDescription);
    fprintf(fptr, "Event Time: %s", asctime(localTime));

    fclose(fptr);
}

int main() {
    char event1Name[] = "The Case of the Missing Code";
    char event1Description[] = "A string of code disappeared from the program.";

    logEvent(event1Name, event1Description);

    char event2Name[] = "The Mysterious Segmentation Fault";
    char event2Description[] = "The program crashed, but there was no obvious reason.";

    logEvent(event2Name, event2Description);

    char event3Name[] = "The Case of the Endless Loop";
    char event3Description[] = "The program entered a never-ending loop.";

    logEvent(event3Name, event3Description);

    printf("Events have been logged successfully.\n");

    return 0;
}