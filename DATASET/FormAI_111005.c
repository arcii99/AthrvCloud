//FormAI DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct log_entry {
    int timestamp;
    char message[100];
} log_entry_t;

int main() {
    log_entry_t log_entries[10];
    int num_entries = sizeof(log_entries) / sizeof(log_entry_t);

    // Generate random log entries
    for (int i = 0; i < num_entries; i++) {
        log_entries[i].timestamp = rand() % 100;
        sprintf(log_entries[i].message, "Log entry %d", i+1);
    }

    // Calculate the average timestamp
    int sum_timestamps = 0;
    for (int i = 0; i < num_entries; i++) {
        sum_timestamps += log_entries[i].timestamp;
    }
    float avg_timestamp = (float) sum_timestamps / num_entries;

    // Find the log entry with the timestamp closest to the average
    log_entry_t closest_entry;
    int closest_diff = abs(log_entries[0].timestamp - avg_timestamp);
    for (int i = 1; i < num_entries; i++) {
        int diff = abs(log_entries[i].timestamp - avg_timestamp);
        if (diff < closest_diff) {
            closest_diff = diff;
            closest_entry = log_entries[i];
        }
    }

    // Print the closest log entry
    printf("Closest log entry to the average timestamp (%f) is:\n", avg_timestamp);
    printf("Timestamp: %d\n", closest_entry.timestamp);
    printf("Message: %s\n", closest_entry.message);

    return 0;
}