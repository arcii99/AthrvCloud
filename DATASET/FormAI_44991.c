//FormAI DATASET v1.0 Category: System event logger ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(const char *eventType, const char *eventDescription) {
    FILE *logFile;
    time_t timestamp;
    char timestampStr[20];
    const char *logFileName = "eventlog.txt";
    
    // Open the event log file
    logFile = fopen(logFileName, "a");
    if (logFile == NULL) {
        fprintf(stderr, "Error: Cannot open log file '%s' for appending.\n", logFileName);
        exit(1);
    }
    
    // Get the current time
    time(&timestamp);
    strftime(timestampStr, sizeof(timestampStr), "%Y-%m-%d %H:%M:%S", localtime(&timestamp));
    
    // Write the event to the log file
    fprintf(logFile, "[%s] [%s] %s\n", timestampStr, eventType, eventDescription);
    
    // Close the event log file
    fclose(logFile);
}

int main() {
    printf("Writing some events to the event log...\n");

    logEvent("INFO", "Program started.");
    logEvent("WARNING", "Low disk space.");
    logEvent("ERROR", "Cannot connect to server.");
    logEvent("INFO", "Program ended.");

    printf("Done.\n");

    return 0;
}