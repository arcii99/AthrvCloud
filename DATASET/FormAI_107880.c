//FormAI DATASET v1.0 Category: Log analysis ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char time[20];
    char level[10];
    char message[MAX_LINE_LENGTH-30];
} LogEntry;

int countEntries(FILE* fp) {
    char line[MAX_LINE_LENGTH];
    int count = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        count++;
    }
    rewind(fp);
    return count;
}

LogEntry* parseLogFile(FILE* fp, int numEntries) {
    LogEntry* logs = malloc(numEntries*sizeof(LogEntry));
    char line[MAX_LINE_LENGTH];
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && i < numEntries) {
        if (strlen(line) <= 30) {
            continue; // Skip blank lines or lines where only time and level are reported
        }
        char* token = strtok(line, " ");
        int tokenIndex = 0;
        while (token != NULL && tokenIndex < 2) {
            if (tokenIndex == 0) {
                strcpy(logs[i].time, token);
            } else {
                strcpy(logs[i].level, token);
            }
            token = strtok(NULL, " ");
            tokenIndex++;
        }
        strcpy(logs[i].message, "");
        while (token != NULL) {
            strcat(logs[i].message, token);
            strcat(logs[i].message, " ");
            token = strtok(NULL, " ");
        }
        logs[i].message[strlen(logs[i].message)-1] = '\0'; // Remove trailing space character
        for (int j = 0; j < strlen(logs[i].message); j++) {
            logs[i].message[j] = tolower(logs[i].message[j]); // Convert message to lowercase
        }
        i++;
    }
    return logs;
}

void printEntries(LogEntry* logs, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%s %s: %s\n", logs[i].time, logs[i].level, logs[i].message);
    }
}

void countLevels(LogEntry* logs, int numEntries) {
    int numDebug = 0, numInfo = 0, numWarning = 0, numError = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(logs[i].level, "DEBUG") == 0) {
            numDebug++;
        } else if (strcmp(logs[i].level, "INFO") == 0) {
            numInfo++;
        } else if (strcmp(logs[i].level, "WARNING") == 0) {
            numWarning++;
        } else if (strcmp(logs[i].level, "ERROR") == 0) {
            numError++;
        }
    }
    printf("Number of DEBUG entries: %d\n", numDebug);
    printf("Number of INFO entries: %d\n", numInfo);
    printf("Number of WARNING entries: %d\n", numWarning);
    printf("Number of ERROR entries: %d\n", numError);
}

int countSubstring(LogEntry* logs, int numEntries, char* substring) {
    int count = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strstr(logs[i].message, substring) != NULL) {
            count++;
        }
    }
    return count;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./log-analyzer [LOGFILE]\n");
        exit(1);
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open log file.\n");
        exit(1);
    }
    int numEntries = countEntries(fp);
    LogEntry* logs = parseLogFile(fp, numEntries);
    printf("Log file contains %d entries:\n", numEntries);
    printEntries(logs, numEntries);
    countLevels(logs, numEntries);
    char substring[MAX_LINE_LENGTH];
    printf("Enter a substring to search for: ");
    fgets(substring, MAX_LINE_LENGTH, stdin);
    substring[strlen(substring)-1] = '\0';
    int numSubstr = countSubstring(logs, numEntries, substring);
    printf("Number of entries containing \"%s\": %d\n", substring, numSubstr);
    free(logs);
    fclose(fp);
    return 0;
}