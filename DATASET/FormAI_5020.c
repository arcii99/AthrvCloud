//FormAI DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>

#define MAX_LOG_MSG_LENGTH 100

typedef struct {
    char time_stamp[20];
    char level[10];
    char message[MAX_LOG_MSG_LENGTH];
} LogEntry;

void print_log_entry(LogEntry entry) {
    printf("[%s] %s: %s\n", entry.time_stamp, entry.level, entry.message);
}

int main() {
    LogEntry log_entries[5] = {
        {"2022-10-09 10:05:40", "INFO", "Application started."},
        {"2022-10-09 10:45:02", "WARNING", "Disk space is running low."},
        {"2022-10-09 11:04:57", "ERROR", "File not found."},
        {"2022-10-09 11:49:23", "INFO", "New user registered."},
        {"2022-10-09 12:18:13", "DEBUG", "Variable x is: 5"}
    };

    int num_entries = 5;

    printf("Log entries:\n\n");
    for (int i = 0; i < num_entries; i++) {
        print_log_entry(log_entries[i]);
    }

    int num_errors = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(log_entries[i].level, "ERROR") == 0) {
            num_errors++;
        }
    }

    printf("\nNumber of errors: %d\n", num_errors);

    LogEntry latest_entry = log_entries[0];
    for (int i = 1; i < num_entries; i++) {
        if (strcmp(log_entries[i].time_stamp, latest_entry.time_stamp) > 0) {
            latest_entry = log_entries[i];
        }
    }

    printf("\nLatest log entry:\n");
    print_log_entry(latest_entry);

    return 0;
}