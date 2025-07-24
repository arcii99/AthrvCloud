//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventType, char* eventDescription, char* sourceFile, int lineNumber) {
    // Get current time
    time_t now;
    time(&now);

    // Format the timestamp
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Open the log file
    FILE * logFile;
    logFile = fopen("event_log.txt", "a");

    // Write the log entry
    fprintf(logFile, "[%s] %s: %s (source: %s line: %d)\n", timestamp, eventType, eventDescription, sourceFile, lineNumber);
    
    // Close the log file
    fclose(logFile);
}

int main() {
    // Test the logger functions
    logEvent("INFO", "Program started", __FILE__, __LINE__);

    int i = 0;
    for (i = 0; i < 5; i++) {
        printf("Logging event %d\n", i);
        logEvent("DEBUG", "Loop iteration", __FILE__, __LINE__);
    }

    logEvent("WARNING", "Memory leak detected", __FILE__, __LINE__);

    // Return success
    return 0;
}