//FormAI DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <time.h>

// function to log events with timestamp
void logEvent(const char* message) {
    time_t currentTime;
    time(&currentTime);
    printf("[%s]: %s\n", ctime(&currentTime), message);
}

// main function to demonstrate event logging
int main() {
    printf("Starting the event logger...\n\n");

    // log some events
    logEvent("System started.");
    logEvent("Connected to database.");
    logEvent("Data processing initiated.");
    logEvent("Data processing completed.");
    logEvent("System stopped.");

    return 0;
}