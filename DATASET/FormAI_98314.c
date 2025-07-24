//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to represent log entries.
typedef struct LogEntry {
    time_t timestamp;
    char *message;
} LogEntry;

// Define a function to create a new log entry.
LogEntry createLogEntry(char *message) {
    LogEntry entry;
    entry.timestamp = time(NULL);
    entry.message = message;
    return entry;
}

// Define a function to print a log entry.
void printLogEntry(LogEntry entry) {
    printf("[%s] %s\n", ctime(&entry.timestamp), entry.message);
}

// Define a function to free memory used by a log entry.
void freeLogEntry(LogEntry *entry) {
    free(entry->message);
}

int main() {
    // Create an array to hold log entries.
    LogEntry log[10];
    int numEntries = 0;

    // Add some log entries.
    log[numEntries++] = createLogEntry("System starting up.");
    log[numEntries++] = createLogEntry("User logged in: johnsmith.");
    log[numEntries++] = createLogEntry("File saved: report.doc.");
    log[numEntries++] = createLogEntry("Warning: low disk space.");

    // Print all log entries.
    printf("All log entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printLogEntry(log[i]);
    }

    // Free memory used by log entries.
    for (int i = 0; i < numEntries; i++) {
        freeLogEntry(&log[i]);
    }

    return 0;
}