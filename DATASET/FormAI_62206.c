//FormAI DATASET v1.0 Category: System event logger ; Style: intelligent
#include <stdio.h>
#include <time.h>

void logEvent(char *eventName, char *eventDescription) {
    // Open the log file for appending
    FILE *logFile = fopen("event-log.txt", "a");

    // If log file opened successfully, write the event information to log file
    if (logFile != NULL) {
        // Get the current time
        time_t rawTime;
        struct tm *currentTime;
        time(&rawTime);
        currentTime = localtime(&rawTime);

        // Write the event information to log file
        fprintf(logFile, "[%04d/%02d/%02d %02d:%02d:%02d] %s: %s\n", 
            1900 + currentTime->tm_year, 
            1 + currentTime->tm_mon, 
            currentTime->tm_mday, 
            currentTime->tm_hour, 
            currentTime->tm_min, 
            currentTime->tm_sec,
            eventName, eventDescription);

        // Close the log file
        fclose(logFile);
    }
    else {
        printf("Error: Could not open event log file!\n");
    }
}

int main() {
    // Log a system event
    logEvent("Error", "Could not initialize system.");

    // Log a user event
    logEvent("User", "User successfully logged in.");

    return 0;
}