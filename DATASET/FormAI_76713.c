//FormAI DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LOG_ENTRIES 1000

typedef struct LogEntry {
    int day;
    int month;
    int year;
    char message[200];
} LogEntry;

typedef struct Log {
    int num_entries;
    LogEntry entries[MAX_LOG_ENTRIES];
} Log;

void print_entry(LogEntry entry) {
    printf("%02d/%02d/%d: %s\n", entry.month, entry.day, entry.year, entry.message);
}

void print_log(Log log) {
    printf("=== LOG ===\n");
    for (int i = 0; i < log.num_entries; i++) {
        print_entry(log.entries[i]);
    }
    printf("==========\n");
}

bool parse_line(char* line, LogEntry* entry) {
    char* token = strtok(line, "/");
    if (token == NULL) return false;
    entry->month = atoi(token);

    token = strtok(NULL, "/");
    if (token == NULL) return false;
    entry->day = atoi(token);

    token = strtok(NULL, ":");
    if (token == NULL) return false;
    entry->year = atoi(token);

    token = strtok(NULL, "");
    if (token == NULL) return false;
    strncpy(entry->message, token, 200);
    entry->message[199] = '\0';

    return true;
}

int main() {
    Log log;
    log.num_entries = 0;

    printf("Enter log messages (MM/DD/YYYY:message), enter -1 to end:\n");

    bool running = true;
    while (running) {
        char line[256];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "-1") == 0) {
            running = false;
        } else {
            if (log.num_entries >= MAX_LOG_ENTRIES) {
                printf("Log is full!\n");
            } else {
                LogEntry entry;
                if (parse_line(line, &entry)) {
                    log.entries[log.num_entries] = entry;
                    log.num_entries++;
                } else {
                    printf("Invalid format! Please use MM/DD/YYYY:message\n");
                }
            }
        }
    }

    print_log(log);

    // perform analysis here
    int num_errors = 0;
    for (int i = 0; i < log.num_entries; i++) {
        char* message = log.entries[i].message;
        if (strstr(message, "ERROR") != NULL || strstr(message, "error") != NULL) {
            num_errors++;
        }
    }

    printf("Number of errors: %d\n", num_errors);

    return 0;
}