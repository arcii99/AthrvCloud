//FormAI DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void logEvent(const char* eventType, const char* eventDescription){
    FILE* logFile;

    logFile = fopen("eventLog.txt", "a");

    if(logFile == NULL){
        printf("Error opening log file!");
        exit(1);
    }

    fprintf(logFile, "Event Type: %s\nEvent Description: %s\n\n", eventType, eventDescription);

    fclose(logFile);
}

int main(){
    char eventType[20], eventDescription[100];

    printf("Enter the event type: ");
    fgets(eventType, 20, stdin);

    printf("Enter the event description: ");
    fgets(eventDescription, 100, stdin);

    logEvent(eventType, eventDescription);

    printf("Event was successfully logged to the file!\n");

    return 0;
}