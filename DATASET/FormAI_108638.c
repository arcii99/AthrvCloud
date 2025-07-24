//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_ENTRIES 1000

// Struct to hold log entries
typedef struct log_entry {
    char datetime[MAX_LINE_LENGTH];
    char src_ip[MAX_LINE_LENGTH];
    char dest_ip[MAX_LINE_LENGTH];
    char protocol[MAX_LINE_LENGTH];
    char message[MAX_LINE_LENGTH];
} log_entry;

// Function to parse log file and store entries in array
void parse_log_file(char *filename, log_entry *log_entries, int *num_entries) {
    FILE *log_file = fopen(filename, "r");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *token;
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        // Split line by comma
        token = strtok(line, ",");
        strcpy(log_entries[*num_entries].datetime, token);

        token = strtok(NULL, ",");
        strcpy(log_entries[*num_entries].src_ip, token);

        token = strtok(NULL, ",");
        strcpy(log_entries[*num_entries].dest_ip, token);

        token = strtok(NULL, ",");
        strcpy(log_entries[*num_entries].protocol, token);

        token = strtok(NULL, ",");
        strcpy(log_entries[*num_entries].message, token);

        (*num_entries)++;
    }

    fclose(log_file);
}

// Function to detect potential intrusions
void detect_intrusions(log_entry *log_entries, int num_entries) {
    char *blacklisted_ips[] = {"127.0.0.1", "192.168.1.1", "10.0.0.1"};
    int num_blacklisted_ips = sizeof(blacklisted_ips) / sizeof(char *);

    for (int i = 0; i < num_entries; i++) {
        // Check if source IP is blacklisted
        for (int j = 0; j < num_blacklisted_ips; j++) {
            if (strcmp(log_entries[i].src_ip, blacklisted_ips[j]) == 0) {
                printf("Potential intrusion detected! Source IP: %s\n", log_entries[i].src_ip);
                break;
            }
        }
    }
}

int main() {
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    parse_log_file("example_log.txt", log_entries, &num_entries);

    detect_intrusions(log_entries, num_entries);

    return 0;
}