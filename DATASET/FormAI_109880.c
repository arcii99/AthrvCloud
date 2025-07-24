//FormAI DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum length of events and log messages
#define EVENT_MAX_LENGTH 50
#define MESSAGE_MAX_LENGTH 100

// Define a struct to hold event information
struct event {
    time_t timestamp;
    char name[EVENT_MAX_LENGTH];
    char message[MESSAGE_MAX_LENGTH];
};

// Define a function to log events
void logEvent(struct event* log, char* eventName, char* message) {
    // Get current timestamp
    time_t current_time = time(NULL);
    
    // Set event information in struct
    log->timestamp = current_time;
    strncpy(log->name, eventName, EVENT_MAX_LENGTH);
    strncpy(log->message, message, MESSAGE_MAX_LENGTH);

    // Print event information to console
    printf("%s - %s: %s\n", ctime(&current_time), log->name, log->message);
}

int main() {
    // Allocate memory for event log
    struct event* eventLog = (struct event*)malloc(sizeof(struct event) * 100);
    if (!eventLog) {
        printf("Failed to allocate memory for event log!");
        return 1;
    }
    
    // Log sample events
    logEvent(&eventLog[0], "System Startup", "The system has started up.");
    logEvent(&eventLog[1], "User Login", "User 'user1' has logged in.");
    logEvent(&eventLog[2], "User Logout", "User 'user2' has logged out.");

    // Free memory allocated for event log
    free(eventLog);

    return 0;
}