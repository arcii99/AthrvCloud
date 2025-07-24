//FormAI DATASET v1.0 Category: System event logger ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void logEvent(char* eventType, char* message) {
    // Get current time
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char* timeStr = asctime(timeinfo);
    timeStr[strlen(timeStr) - 1] = '\0'; // Remove newline character

    // Print log message with event type, message, and timestamp
    printf("[%s] %s: %s\n", timeStr, eventType, message);

    // Open log file in append mode
    FILE* logFile = fopen("event.log", "a");

    // Write log message to log file with event type, message, and timestamp
    fprintf(logFile, "[%s] %s: %s\n", timeStr, eventType, message);

    // Close log file
    fclose(logFile);
}

int main() {
    // Log test events
    logEvent("INFO", "Program started");
    logEvent("ERROR", "File not found");
    logEvent("WARNING", "Memory leak detected");
    logEvent("DEBUG", "Variable value: 42");

    return 0;
}