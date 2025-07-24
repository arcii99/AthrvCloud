//FormAI DATASET v1.0 Category: System event logger ; Style: realistic
#include <stdio.h>
#include <time.h>

void logEvent(char* message) {

    time_t currentTime;
    char timeString[25];
    time(&currentTime);

    // Format time
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

    // Open log file
    FILE* logFile = fopen("eventLog.txt", "a");

    // Write entry to log file
    fprintf(logFile, "[%s] %s\n", timeString, message);

    // Close log file
    fclose(logFile);
}

int main() {

    // Log some events
    logEvent("System startup");
    logEvent("Initializing components");
    logEvent("Connection established");
    logEvent("Data received");
    logEvent("System shutdown");

    // Confirm successful logging
    printf("Events logged successfully.\n");

    return 0;
}