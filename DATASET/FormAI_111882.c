//FormAI DATASET v1.0 Category: Log analysis ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom struct to hold log information
typedef struct LogEntry {
    char *timestamp;
    char *level;
    char *message;
} LogEntry;

// Function to parse a single log entry string
LogEntry parseLogEntry(char *entryStr) {
    // Split the string into its three parts
    char *timestamp = strtok(entryStr, "|");
    char *level = strtok(NULL, "|");
    char *message = strtok(NULL, "");

    // Allocate memory for the new LogEntry struct
    LogEntry entry;
    entry.timestamp = malloc(strlen(timestamp) + 1);
    entry.level = malloc(strlen(level) + 1);
    entry.message = malloc(strlen(message) + 1);

    // Copy the parsed values into the struct
    strcpy(entry.timestamp, timestamp);
    strcpy(entry.level, level);
    strcpy(entry.message, message);

    return entry;
}

// Function to print a LogEntry struct
void printLogEntry(LogEntry entry) {
    printf("%s | %s | %s\n", entry.timestamp, entry.level, entry.message);
}

int main() {
    // Simulate reading in log entries from a file
    char *logFileContents = "2022-08-01 11:00:01|INFO|Starting program.\n"
                            "2022-08-01 11:00:02|WARN|No input file provided.\n"
                            "2022-08-01 11:00:03|ERROR|Unable to open input file.\n"
                            "2022-08-01 11:00:04|INFO|Exiting program.";

    // Split the file contents into individual log entry strings
    char *entryStrs[4];
    entryStrs[0] = strtok(logFileContents, "\n");
    for (int i = 1; i < 4; i++) {
        entryStrs[i] = strtok(NULL, "\n");
    }

    // Parse each log entry string into a LogEntry struct
    LogEntry entries[4];
    for (int i = 0; i < 4; i++) {
        entries[i] = parseLogEntry(entryStrs[i]);
    }

    // Print the log entries that have an ERROR level
    printf("ERRORS:\n");
    for (int i = 0; i < 4; i++) {
        if (strcmp(entries[i].level, "ERROR") == 0) {
            printLogEntry(entries[i]);
        }
    }

    // Print all log entries
    printf("\nALL LOG ENTRIES:\n");
    for (int i = 0; i < 4; i++) {
        printLogEntry(entries[i]);
    }

    // Free the memory allocated for the log entry strings and structs
    for (int i = 0; i < 4; i++) {
        free(entryStrs[i]);
        free(entries[i].timestamp);
        free(entries[i].level);
        free(entries[i].message);
    }

    return 0;
}