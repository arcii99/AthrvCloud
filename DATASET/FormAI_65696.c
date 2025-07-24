//FormAI DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// System event logger structure
struct SystemEventLog {
    char* timestamp;
    char* event;
};

// Function to add system event to log
void addEventLog(struct SystemEventLog *eventLog, char* event) {
    // Get current time
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Convert time to string format
    char* timestamp = asctime(timeinfo);

    // Add event to log
    eventLog->timestamp = timestamp;
    eventLog->event = event;

    // Print event message with timestamp
    printf("%s - %s\n", eventLog->timestamp, eventLog->event);
}

int main() {
    // Initialize system event log
    struct SystemEventLog eventLog;

    // Sample events to log
    char* event1 = "User logged in";
    char* event2 = "File saved successfully";
    char* event3 = "Database connection failed";
    char* event4 = "System restarted";

    // Add events to log
    addEventLog(&eventLog, event1);
    addEventLog(&eventLog, event2);
    addEventLog(&eventLog, event3);
    addEventLog(&eventLog, event4);

    return 0;
}