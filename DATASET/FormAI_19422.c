//FormAI DATASET v1.0 Category: System event logger ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventType, char* eventDescription) {
    // Get current time and date
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    char timestamp[25];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    // Open log file in write mode
    FILE* logFile = fopen("eventLog.txt", "a");
    if (logFile == NULL) {
        printf("Error opening log file!\n");
        exit(EXIT_FAILURE);
    }

    // Write event details to log file
    fprintf(logFile, "[%s] Event Type: %s | Event Description: %s\n", timestamp, eventType, eventDescription);

    // Close log file
    fclose(logFile);
}

int main() {
    // Log example events
    logEvent("INFO", "Program started.");
    logEvent("WARNING", "User input validation failed.");
    logEvent("ERROR", "Out of memory.");
    logEvent("DEBUG", "Variable value before loop: 5");
    logEvent("INFO", "Program ended.");

    return 0;
}