//FormAI DATASET v1.0 Category: System event logger ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logSystemEvent(char* filename, char* message);

int main(void) {
    char* filename = "system_events.log";
    char* eventMessage = "Error: Unable to connect to server.";

    // Get current datetime
    time_t now;
    time(&now);
    char dateTime[20];
    strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Create log message
    char logMessage[1000];
    sprintf(logMessage, "[%s] %s\n", dateTime, eventMessage);

    // Log system event
    logSystemEvent(filename, logMessage);

    printf("System event logged successfully!\n");

    return 0;
}

/* Logs a system event to a specified log file */
void logSystemEvent(char* filename, char* message) {
    FILE* file = fopen(filename, "a");
    
    if (file == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    fprintf(file, "%s", message);
    fclose(file);
}