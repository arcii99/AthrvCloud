//FormAI DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(const char* eventName, const char* eventDescription) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char buffer[80];

    // Format the time string
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

    // Open the log file for appending
    FILE* file = fopen("event_log.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write the log message to the file
    fprintf(file, "[%s] %s - %s\n", buffer, eventName, eventDescription);

    // Close the file
    fclose(file);
}

int main(void) {
    // Log some events
    logEvent("System Boot", "The system has started up.");
    logEvent("Login", "User 'johndoe' has logged in.");
    logEvent("Error", "An error occurred while processing the request.");

    printf("Events logged to event_log.txt\n");

    return 0;
}