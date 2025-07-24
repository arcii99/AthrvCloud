//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000

// Structure for each log entry
typedef struct LogEntry {
    char timestamp[20];
    char message[100];
} LogEntry;

// Data structure to hold the log entries
LogEntry logBuffer[MAX_LOG_SIZE];

// Function to add an entry to the log buffer
void addLogEntry(char* timestamp, char* message) {
    // Check if log buffer is full
    if (sizeof(logBuffer) / sizeof(LogEntry) == MAX_LOG_SIZE) {
        printf("Log buffer full. Intrusion detected!\n");
        exit(1);
    }
    // Add entry to buffer
    LogEntry newEntry;
    strcpy(newEntry.timestamp, timestamp);
    strcpy(newEntry.message, message);
    logBuffer[sizeof(logBuffer) / sizeof(LogEntry)] = newEntry;
}

int main() {
    // Assume logs are coming in as strings in the format
    // TIMESTAMP | MESSAGE
    char logEntryStr[] = "2022-07-30 10:55:12 | User admin logged in";
    char* timestamp = strtok(logEntryStr, " |");
    char* message = strtok(NULL, " |");
    addLogEntry(timestamp, message);

    // Example for checking log buffer
    for (int i = 0; i < sizeof(logBuffer) / sizeof(LogEntry); i++) {
        printf("%s - %s\n", logBuffer[i].timestamp, logBuffer[i].message);
    }

    return 0;
}