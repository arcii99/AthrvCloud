//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LENGTH 1024
#define ALERT_THRESHOLD 10

// Function declarations
void log_event(char *event, char *ip_address);
int check_alert(char *ip_address);

// Struct to store log data
typedef struct {
    char event[MAX_LOG_LENGTH];
    char ip_address[16];
} log_entry_t;

// Array to store log entries
log_entry_t log_entries[MAX_LOG_LENGTH];

// Number of entries in log array
int num_entries = 0;

int main(void) {
    char input[MAX_LOG_LENGTH];
    char *event;
    char *ip_address;
    int alert;

    while (1) {
        // Prompt user for input
        printf("> ");
        fgets(input, MAX_LOG_LENGTH, stdin);

        // Parse input
        event = strtok(input, " ");
        if (event == NULL) {
            printf("Error: invalid input\n");
            continue;
        }
        ip_address = strtok(NULL, "\n");
        if (ip_address == NULL) {
            printf("Error: invalid input\n");
            continue;
        }

        // Log event
        log_event(event, ip_address);

        // Check for alert
        alert = check_alert(ip_address);
        if (alert) {
            printf("ALERT: %s has exceeded the threshold of %d events\n", ip_address, ALERT_THRESHOLD);
        }
    }

    return 0;
}

void log_event(char *event, char *ip_address) {
    // Check if log array is full
    if (num_entries == MAX_LOG_LENGTH) {
        // Shift entries to make room for new entry
        for (int i = 0; i < MAX_LOG_LENGTH - 1; i++) {
            strcpy(log_entries[i].event, log_entries[i+1].event);
            strcpy(log_entries[i].ip_address, log_entries[i+1].ip_address);
        }
        num_entries--;
    }

    // Add new entry
    strcpy(log_entries[num_entries].event, event);
    strcpy(log_entries[num_entries].ip_address, ip_address);
    num_entries++;
}

int check_alert(char *ip_address) {
    int count = 0;

    // Count events for given IP address
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(log_entries[i].ip_address, ip_address) == 0) {
            count++;
        }
    }

    // Check if count exceeds threshold
    if (count >= ALERT_THRESHOLD) {
        return 1;
    } else {
        return 0;
    }
}