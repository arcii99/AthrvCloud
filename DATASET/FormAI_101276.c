//FormAI DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

Welcome to the C System Event Logger program!
This program will allow you to log events on your system.
Once an event is logged, it will be saved in a file for later retrieval.
Let's get started!

*/

int main(void) {

    FILE *filePointer; // Declare file pointer
    filePointer = fopen("event_log.txt", "a"); // Open file in append mode

    if (filePointer == NULL) { // Check if file is null
        printf("Error: Unable to open file.\n");
        return 1; // Exit program with error status
    }

    time_t rawTime;
    struct tm *currentTime;
    char event[100];

    printf("Welcome to the C System Event Logger!\n");
    printf("Please enter the event you would like to log: ");
    fgets(event, sizeof(event), stdin); // Get event from user

    rawTime = time(NULL);
    currentTime = localtime(&rawTime); // Get current local time

    fprintf(filePointer, "%d/%d/%d %d:%d:%d -- %s\n", 
        (currentTime->tm_mon + 1), currentTime->tm_mday, 
        (currentTime->tm_year + 1900), currentTime->tm_hour, 
        currentTime->tm_min, currentTime->tm_sec, event); // Write event to file

    printf("Event logged successfully!\n");
    fclose(filePointer); // Close file

    return 0; // Exit program with success status
}