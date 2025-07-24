//FormAI DATASET v1.0 Category: Log analysis ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct LogEntry {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

int main(int argc, char *argv[]) {
    FILE *file = fopen("example.log", "r");
    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    // Read the log entries from the file
    LogEntry logEntries[MAX_LINE_LENGTH];
    int nEntries = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (nEntries == MAX_LINE_LENGTH) {
            printf("Too many log entries\n");
            return 1;
        }

        // Parse the log entry
        char *timestamp = strtok(line, " ");
        char *level = strtok(NULL, " ");
        char *message = strtok(NULL, "\n");

        strcpy(logEntries[nEntries].timestamp, timestamp);
        strcpy(logEntries[nEntries].level, level);
        strcpy(logEntries[nEntries].message, message);

        nEntries++;
    }

    // Print the log entries to stdout
    for (int i = 0; i < nEntries; i++) {
        printf("%s %s %s\n", logEntries[i].timestamp, logEntries[i].level, logEntries[i].message);
    }

    return 0;
}