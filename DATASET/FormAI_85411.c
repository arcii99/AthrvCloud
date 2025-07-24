//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Struct for storing log entries
typedef struct {
    char *date;
    char *time;
    char *description;
} LogEntry;

// Function to parse log file and return array of LogEntries
LogEntry* parseLogFile(char *fileName, int *numEntries) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LENGTH];
    int count = 0;
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        count++;
    }

    LogEntry *logEntries = malloc(count * sizeof(LogEntry));
    if (logEntries == NULL) {
        printf("Error: Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_SET);
    int index = 0;
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        char *token = strtok(line, " ");
        logEntries[index].date = strdup(token);

        token = strtok(NULL, ",");
        logEntries[index].time = strdup(token);

        token = strtok(NULL, "\n");
        logEntries[index].description = strdup(token);

        index++;
    }

    fclose(file);
    *numEntries = count;
    return logEntries;
}

// Function to print all log entries
void printLogEntries(LogEntry *logEntries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%s %s - %s\n", logEntries[i].date, logEntries[i].time, logEntries[i].description);
    }
}

// Function to filter log entries by keyword and print them
void filterLogEntries(LogEntry *logEntries, int numEntries, char *keywords[], int numKeywords) {
    for (int i = 0; i < numEntries; i++) {
        for (int j = 0; j < numKeywords; j++) {
            if (strstr(logEntries[i].description, keywords[j]) != NULL) {
                printf("%s %s - %s\n", logEntries[i].date, logEntries[i].time, logEntries[i].description);
                break;
            }
        }
    }
}

int main() {
    char *fileName = "log.txt";

    int numEntries;
    LogEntry *logEntries = parseLogFile(fileName, &numEntries);

    printf("All log entries:\n");
    printLogEntries(logEntries, numEntries);

    char *keywords[] = {"error", "warning"};
    int numKeywords = 2;

    printf("\nFiltered log entries (error or warning):\n");
    filterLogEntries(logEntries, numEntries, keywords, numKeywords);

    // Free memory allocated for log entries
    for (int i = 0; i < numEntries; i++) {
        free(logEntries[i].date);
        free(logEntries[i].time);
        free(logEntries[i].description);
    }
    free(logEntries);

    return 0;
}