//FormAI DATASET v1.0 Category: System event logger ; Style: active
#include <stdio.h>
#include <time.h>

void logEvent(const char* eventDesc) {
    time_t rawtime;
    struct tm* timeInfo;
    char timestamp[30];

    time(&rawtime);
    timeInfo = localtime(&rawtime);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeInfo);

    // Open the log file in append mode
    FILE* logFile = fopen("event_logs.txt", "a");

    if (logFile == NULL) {
        printf("Error: event log file could not be opened.\n");
        return;
    }

    // Write the event to the log file
    fprintf(logFile, "[%s]: %s\n", timestamp, eventDesc);

    // Close the log file
    fclose(logFile);

    // Display the event on the console
    printf("[%s]: %s\n", timestamp, eventDesc);
}

int main() {
    // Log some example events
    logEvent("User logged in.");
    logEvent("User clicked on the homepage.");
    logEvent("Database connection error.");

    return 0;
}