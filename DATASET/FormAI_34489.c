//FormAI DATASET v1.0 Category: System event logger ; Style: random
#include <stdio.h>
#include <time.h>

// Function to log a system event
void logEvent(char* description) {
    // Get the current time
    time_t t;
    time(&t);
    struct tm* localTime = localtime(&t);

    // Open the log file in append mode
    FILE* logFile = fopen("system.log", "a");

    // Check if the file was successfully opened
    if (logFile == NULL) {
        printf("Error: Could not open log file!");
        return;
    }

    // Print the timestamp and event description to the log file
    fprintf(logFile, "[%02d/%02d/%4d %02d:%02d:%02d] %s\n",
            localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900,
            localTime->tm_hour, localTime->tm_min, localTime->tm_sec, description);

    // Close the log file
    fclose(logFile);
}

int main() {
    printf("Welcome to the Event Logger!\n");

    // Log some example events
    logEvent("System started up successfully.");
    logEvent("User logged in.");
    logEvent("System encountered an error.");
    logEvent("Critical process completed.");

    printf("Events logged to system.log.\n");

    return 0;
}