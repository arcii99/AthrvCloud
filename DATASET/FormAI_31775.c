//FormAI DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_SIZE 100 // Maximum number of log entries

// Definition of a log entry
typedef struct LogEntry {
    time_t timestamp;
    char message[80];
} LogEntry;

// Function to log a message
void logEvent(char* message, LogEntry* logs, int* index) {
    if (*index == MAX_LOG_SIZE) {
        printf("Log is full!\n");
        return;
    }
    LogEntry entry;
    entry.timestamp = time(NULL);
    strcpy(entry.message, message);
    logs[*index] = entry;
    (*index)++;
}

// Function to print all log entries
void printLogs(LogEntry* logs, int index) {
    printf("----- System Event Log -----\n");
    for (int i = 0; i < index; i++) {
        printf("%s - %s", ctime(&logs[i].timestamp), logs[i].message);
    }
}

// Main function
int main() {
    LogEntry logs[MAX_LOG_SIZE];
    int index = 0;

    printf("Welcome to the System Event logger!\n");

    while (1) {
        printf("Enter a system event message (or type 'quit' to exit): ");
        char message[80];
        fgets(message, 80, stdin);
        message[strcspn(message, "\n")] = 0; // Remove trailing newline character

        if (strcmp(message, "quit") == 0) {
            break;
        }

        logEvent(message, logs, &index);
    }

    printLogs(logs, index);

    return 0;
}