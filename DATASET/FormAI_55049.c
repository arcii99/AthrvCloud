//FormAI DATASET v1.0 Category: System event logger ; Style: high level of detail
#include <stdio.h>
#include <time.h>

void logEvent(const char* eventName, const char* eventDescription) {
    // Get the current time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    // Open the log file for appending events
    FILE* logFile = fopen("events.log", "a");
    if (!logFile) {
        printf("Error: Failed to open events.log file for writing.");
        return;
    }
    
    // Write the event to the log file
    fprintf(logFile, "[%04d-%02d-%02d %02d:%02d:%02d] %s: %s\n", 
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, eventName, eventDescription);
    
    // Close the log file
    fclose(logFile);
}

int main() {
    // Log some events
    logEvent("System Startup", "The system has started up successfully.");
    logEvent("Warning", "The CPU temperature has exceeded its safe limit.");
    logEvent("Error", "Failed to connect to the database server.");
    
    return 0;
}