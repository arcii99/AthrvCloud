//FormAI DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200
#define MAX_LOG_ENTRIES 100

// Struct to hold each log entry
typedef struct LogEntry {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

// Function to parse log files and create array of LogEntry structs
int parseLog(char* filename, LogEntry* logEntries) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }
    
    int numEntries = 0;
    char line[MAX_LINE_LENGTH];
    char delim[] = " []";
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char* token = strtok(line, delim);
        int tokenCount = 0;
        LogEntry entry;
        while (token != NULL) {
            tokenCount++;
            if (tokenCount == 1) {
                strcpy(entry.timestamp, token);
            } else if (tokenCount == 2) {
                strcpy(entry.level, token);
            } else {
                strcat(entry.message, token);
                strcat(entry.message, " ");
            }
            token = strtok(NULL, delim);
        }
        logEntries[numEntries] = entry;
        numEntries++;
    }
    
    fclose(file);
    return numEntries;
}

// Function to print each log entry in array
void printLog(LogEntry* logEntries, int numEntries) {
    printf("Log Entries:\n\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s [%s]: %s\n", logEntries[i].timestamp, logEntries[i].level, logEntries[i].message);
    }
}

// Main function to run program
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: log-analyzer <log-file>\n");
        return 0;
    }
    
    char* filename = argv[1];
    LogEntry logEntries[MAX_LOG_ENTRIES];
    int numEntries = parseLog(filename, logEntries);
    
    if (numEntries < 0) {
        return 0;
    }
    
    printLog(logEntries, numEntries);
    
    return 0;
}