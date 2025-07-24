//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

struct LogEntry {
    char* message;
    int severity;
};

void log_entry(struct LogEntry* log, char* message, int severity);
void check_for_intrusion(struct LogEntry* log);

int main() {
    struct LogEntry log[MAX_LOG_ENTRIES];
    memset(log, 0, sizeof(struct LogEntry) * MAX_LOG_ENTRIES);

    // Simulate some log entries
    log_entry(&log[0], "Accessing restricted file", 5);
    log_entry(&log[1], "Invalid login attempt from unknown ip address", 10);
    log_entry(&log[2], "Enter password", 3);
    log_entry(&log[3], "Permission denied", 8);
    log_entry(&log[4], "Unrecognized command entered", 6);

    // Check for intrusion attempts
    check_for_intrusion(log);

    return 0;
}

void log_entry(struct LogEntry* log, char* message, int severity) {
    for(int i = 0; i < MAX_LOG_ENTRIES; i++) {
        // Find the first empty log entry and use it
        if(log[i].message == NULL) {
            log[i].message = message;
            log[i].severity = severity;
            return;
        }
    }

    // If there are no empty log entries, overwrite the oldest one
    log[0].message = message;
    log[0].severity = severity;
    for(int i = 1; i < MAX_LOG_ENTRIES; i++) {
        log[i-1] = log[i];
    }
    log[MAX_LOG_ENTRIES-1].message = NULL;
    log[MAX_LOG_ENTRIES-1].severity = 0;
}

void check_for_intrusion(struct LogEntry* log) {
    int intrusion_detected = 0;

    // Check for invalid login attempts
    for(int i = 0; i < MAX_LOG_ENTRIES; i++) {
        if(log[i].message != NULL && strstr(log[i].message, "Invalid login attempt") != NULL) {
            intrusion_detected = 1;
            printf("Intrusion detected: %s (Severity: %d)\n", log[i].message, log[i].severity);
        }
    }

    // Check for file access attempts
    for(int i = 0; i < MAX_LOG_ENTRIES; i++) {
        if(log[i].message != NULL && strstr(log[i].message, "Accessing restricted file") != NULL) {
            intrusion_detected = 1;
            printf("Intrusion detected: %s (Severity: %d)\n", log[i].message, log[i].severity);
        }
    }

    if(!intrusion_detected) {
        printf("No intrusion detected\n");
    }
}