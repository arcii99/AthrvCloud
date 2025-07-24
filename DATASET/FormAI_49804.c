//FormAI DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_MSG_LENGTH 100

struct LogEntry {
    int timestamp;
    char message[MAX_LOG_MSG_LENGTH];
};

typedef struct LogEntry LogEntry;

int main() {
    LogEntry logEntries[10];
    int numEntries = 0;

    // Sample log messages
    char *msg1 = "Application is starting up.";
    char *msg2 = "User logged in.";
    char *msg3 = "File saved successfully.";

    // Sample log timestamps
    int timestamp1 = 1000;
    int timestamp2 = 2000;
    int timestamp3 = 3000;

    // Simulate logging by adding log entries
    addLogEntry(logEntries, &numEntries, msg1, timestamp1);
    addLogEntry(logEntries, &numEntries, msg2, timestamp2);
    addLogEntry(logEntries, &numEntries, msg3, timestamp3);

    // Print out the log entries
    printLogEntries(logEntries, numEntries);

    return 0;
}

// Add a new log entry to the array of logEntries
void addLogEntry(LogEntry logEntries[], int *numEntries, char *message, int timestamp) {
    // Create a new LogEntry
    LogEntry newEntry;
    newEntry.timestamp = timestamp;
    strcpy(newEntry.message, message);

    // Add the new entry to the logEntries array
    if (*numEntries < 10) {
        logEntries[*numEntries] = newEntry;
        (*numEntries)++;
    }
}

// Print out all the log entries in the array of logEntries
void printLogEntries(LogEntry logEntries[], int numEntries) {
    printf("%-20s %s\n", "Timestamp", "Message");
    printf("--------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%-20d %s\n", logEntries[i].timestamp, logEntries[i].message);
    }
}