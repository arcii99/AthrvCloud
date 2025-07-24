//FormAI DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20
#define MAX_LEVEL_LENGTH 10
#define MAX_MESSAGE_LENGTH 200

typedef struct LogEntry {
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
    char level[MAX_LEVEL_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} LogEntry;

void printHeader() {
    printf(" __        __   _                          \n");
    printf(" \\ \\      / /__| | ___ ___  _ __ ___       \n");
    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\   \n");
    printf("   \\ V  V /  __/ | (_| (_) | | | | | |    \n");
    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|  \n\n");
}

int main() {
    printHeader();

    FILE *fp;
    char filename[] = "example.log";
    char line[1000];

    printf("Reading log file: %s\n\n", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    LogEntry logEntries[MAX_LOG_ENTRIES];
    int numEntries = 0;

    while (fgets(line, sizeof(line), fp)) {
        // Parse the log entry
        char *date = strtok(line, " ");
        char *time = strtok(NULL, " ");
        char *level = strtok(NULL, " ");
        char *message = strtok(NULL, "\n");

        // Add the log entry to the array
        if (date != NULL && time != NULL && level != NULL && message != NULL) {
            strcpy(logEntries[numEntries].date, date);
            strcpy(logEntries[numEntries].time, time);
            strcpy(logEntries[numEntries].level, level);
            strcpy(logEntries[numEntries].message, message);
            numEntries++;
        }
    }

    fclose(fp);

    printf("Log file contains %d entries.\n\n", numEntries);
    printf("------------------------------\n");

    // Print all log entries
    for (int i = 0; i < numEntries; i++) {
        printf("%s %s %s - %s\n", logEntries[i].date, logEntries[i].time, logEntries[i].level, logEntries[i].message);
    }

    printf("------------------------------\n");

    return 0;
}