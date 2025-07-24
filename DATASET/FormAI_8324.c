//FormAI DATASET v1.0 Category: System event logger ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(int type, char *message) {
    // Get current time
    time_t currTime;
    time(&currTime);
    char *timeStr = ctime(&currTime);
    
    // Open log file for appending
    FILE *logFile = fopen("eventlog.txt", "a");
    if (logFile == NULL) {
        printf("Error: Unable to open log file.\n");
        exit(1);
    }
    
    // Print log entry to file
    switch (type) {
        case 1:
            fprintf(logFile, "[%s] ERROR: %s\n", timeStr, message);
            break;
        case 2:
            fprintf(logFile, "[%s] WARNING: %s\n", timeStr, message);
            break;
        case 3:
            fprintf(logFile, "[%s] INFO: %s\n", timeStr, message);
            break;
        default:
            printf("Error: Invalid event type.\n");
            exit(1);
    }
    
    // Close file
    fclose(logFile);
}

int main() {
    // Log some events
    logEvent(1, "File not found.");
    logEvent(2, "Low disk space.");
    logEvent(3, "Application started.");
    
    // Done
    return 0;
}