//FormAI DATASET v1.0 Category: System event logger ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1000
#define MAX_LOG_LEN 10000

typedef struct {
    time_t timestamp;
    char message[MAX_LOG_LEN];
} LogEntry;

int logCount = 0;

void logEvent(char* message) {
    LogEntry entry;
    entry.timestamp = time(NULL);
    strncpy(entry.message, message, MAX_LOG_LEN);

    FILE* logFile = fopen("eventlog.txt", "a");
    if (logFile == NULL) {
        printf("Error: Could not open log file!\n");
        return;
    }

    fwrite(&entry, sizeof(LogEntry), 1, logFile);

    logCount++;

    if (logCount >= MAX_LOG_SIZE) {
        printf("Warning: Log has reached maximum size. Truncating!\n");
        // Copy the last entries to the beginning and truncate the file
        fseek(logFile, -1 * MAX_LOG_SIZE * sizeof(LogEntry), SEEK_END);

        int bytesRead = 0;
        int bytesToRead = MAX_LOG_SIZE * sizeof(LogEntry);
        char buffer[bytesToRead];

        while (bytesRead < bytesToRead) {
            int result = fread(&buffer[bytesRead], 1, bytesToRead - bytesRead, logFile);
            if (result == 0) {
                break;
            }
            bytesRead += result;
        }

        rewind(logFile);
        fwrite(buffer, sizeof(char), bytesRead, logFile);
        fflush(logFile);

        logCount = MAX_LOG_SIZE - 1;
    }

    fclose(logFile);
}

int main(int argc, char** argv) {
    char message[MAX_LOG_LEN];

    printf("Enter message to log: ");
    fgets(message, MAX_LOG_LEN, stdin);
    // Remove trailing newline
    message[strcspn(message, "\n")] = '\0';

    logEvent(message);

    printf("Event logged successfully!\n");

    return 0;
}