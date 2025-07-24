//FormAI DATASET v1.0 Category: System event logger ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get current time
void getTime(char *timeStr)
{
    time_t currentTime;
    time(&currentTime);
    sprintf(timeStr, "%s", ctime(&currentTime));
}

// Function to log system event
void logEvent(char *event)
{
    FILE *fptr; // File pointer
    char timeStr[30]; // String to store time stamp
    char fileName[50] = "system_events.log"; // File name for log file

    getTime(timeStr); // Get current time

    // Open log file in append mode
    fptr = fopen(fileName, "a");

    // Write event and time stamp to log file
    fprintf(fptr, "%s: %s\n", timeStr, event);

    // Close file
    fclose(fptr);
}

int main()
{
    // Log system events
    logEvent("System started successfully");
    logEvent("User logged in");
    logEvent("File saved successfully");

    return 0;
}