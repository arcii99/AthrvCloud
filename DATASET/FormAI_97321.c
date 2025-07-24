//FormAI DATASET v1.0 Category: System event logger ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This is my awesome event logger!
//It logs all systems events and timestamps them!

int main() {

    time_t currTime;
    char* timeString;
    FILE* logFile;

    printf("Welcome to the System Event Logger!\n");

    // Creating a log file
    logFile = fopen("system_log.txt", "a");

    if(logFile == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get current time
    currTime = time(NULL);

    // Convert time to string format
    timeString = ctime(&currTime);

    // Write the header to the log file
    fprintf(logFile, "\n------------------------------\n");
    fprintf(logFile, "System Event Log on: %s", timeString);
    fprintf(logFile, "------------------------------\n");

    printf("The log file has been created!\n");
    printf("Please enter the event details:\n");

    char event[100];

    // Get event details from the user
    fgets(event, 100, stdin);

    // Remove the newline character from the input string
    event[strcspn(event, "\n")] = 0;

    // Get current time
    currTime = time(NULL);

    // Convert time to string format
    timeString = ctime(&currTime);

    // Write the event details to the log file
    fprintf(logFile, "\n-----------------------------------\n");
    fprintf(logFile, "%s", timeString);
    fprintf(logFile, "Event Details: %s\n", event);
    fprintf(logFile, "-----------------------------------\n");

    printf("Event successfully logged in the system log!\n");

    fclose(logFile); // Close the log file

    return 0; // End of program
}