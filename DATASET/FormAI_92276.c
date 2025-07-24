//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 1000
#define THRESHOLD 10

typedef struct log_entry {
    char *source_ip;
    char *destination_ip;
    char *timestamp;
} log_entry_t;

log_entry_t log_entries[MAX_LOGS];
int num_logs = 0;

void add_log_entry(char *source_ip, char *destination_ip, char *timestamp) {
    log_entry_t entry;
    entry.source_ip = strdup(source_ip);
    entry.destination_ip = strdup(destination_ip);
    entry.timestamp = strdup(timestamp);

    log_entries[num_logs++] = entry;
}

void analyze_logs() {
    int suspicious_count = 0;
    char *suspicious_ips[MAX_LOGS];
    int suspicious_indexes[MAX_LOGS];
    int num_suspicious = 0;

    for (int i = 0; i < num_logs; i++) {
        char *source_ip = log_entries[i].source_ip;
        int count = 0;

        for (int j = 0; j < num_logs; j++) {
            if (i == j) {
                continue;
            }

            char *ip = log_entries[j].source_ip;

            if (strcmp(source_ip, ip) == 0) {
                count++;
            }
        }

        if (count > THRESHOLD && !is_suspicious(source_ip, suspicious_ips, num_suspicious)) {
            suspicious_ips[num_suspicious++] = strdup(source_ip);
            suspicious_indexes[suspicious_count++] = i;
        }
    }

    printf("Suspicious IPs:\n");

    for (int i = 0; i < num_suspicious; i++) {
        printf("%s\n", suspicious_ips[i]);
    }

    printf("Suspicious log entries:\n");

    for (int i = 0; i < suspicious_count; i++) {
        log_entry_t entry = log_entries[suspicious_indexes[i]];
        printf("%s %s %s\n", entry.source_ip, entry.destination_ip, entry.timestamp);
    }
}

int is_suspicious(char *ip, char **suspicious_ips, int num_suspicious) {
    for (int i = 0; i < num_suspicious; i++) {
        if (strcmp(ip, suspicious_ips[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void free_logs() {
    for (int i = 0; i < num_logs; i++) {
        free(log_entries[i].source_ip);
        free(log_entries[i].destination_ip);
        free(log_entries[i].timestamp);
    }
}

int main() {
    add_log_entry("192.168.1.1", "8.8.8.8", "2021-01-01 12:00:00");
    add_log_entry("192.168.1.2", "8.8.8.8", "2021-01-01 12:01:00");
    add_log_entry("192.168.1.1", "8.8.8.8", "2021-01-01 12:02:00");
    add_log_entry("192.168.1.2", "1.1.1.1", "2021-01-01 12:03:00");
    add_log_entry("192.168.1.1", "8.8.8.8", "2021-01-01 12:04:00");
    add_log_entry("192.168.1.1", "1.1.1.1", "2021-01-01 12:05:00");
    add_log_entry("192.168.1.2", "1.1.1.1", "2021-01-01 12:06:00");
    add_log_entry("192.168.1.2", "8.8.8.8", "2021-01-01 12:07:00");
    add_log_entry("192.168.1.1", "8.8.8.8", "2021-01-01 12:08:00");
    add_log_entry("192.168.1.2", "1.1.1.1", "2021-01-01 12:09:00");

    analyze_logs();

    free_logs();

    return 0;
}