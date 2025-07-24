//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_FAILED_LOGINS 3

typedef struct {
    char* ip_address;
    char* timestamp;
    char* action;
} LogEntry;

typedef struct {
    char* ip_address;
    int failed_attempts;
} SuspiciousIP;

void process_log_entry(LogEntry* entry, SuspiciousIP* suspicious_ips, int* num_suspicious_ips) {
    // Check if the entry is a failed login attempt
    if (strcmp(entry->action, "failed_login") == 0) {
        // Check if the IP address is already in the suspicious IP list
        int found = 0;
        for (int i = 0; i < *num_suspicious_ips; i++) {
            if (strcmp(suspicious_ips[i].ip_address, entry->ip_address) == 0) {
                found = 1;
                suspicious_ips[i].failed_attempts++;
                if (suspicious_ips[i].failed_attempts >= MAX_FAILED_LOGINS) {
                    printf("Intrusion detected from IP address %s\n", suspicious_ips[i].ip_address);
                    // TODO: handle the intrusion event (e.g. notify security team, block IP address)
                }
                break;
            }
        }
        // If the IP address is not in the suspicious IP list, add it
        if (!found) {
            SuspiciousIP new_suspicious_ip = {entry->ip_address, 1};
            suspicious_ips[*num_suspicious_ips] = new_suspicious_ip;
            (*num_suspicious_ips)++;
        }
    }
}

int main() {
    LogEntry log_entries[MAX_LOG_ENTRIES];
    SuspiciousIP suspicious_ips[MAX_LOG_ENTRIES];
    int num_log_entries = 0;
    int num_suspicious_ips = 0;
    
    // TODO: read log entries from file or network interface
    // For now, we'll just hardcode some sample log entries
    LogEntry entry1 = {"10.0.0.1", "2022-01-01 12:00:00", "failed_login"};
    LogEntry entry2 = {"10.0.0.2", "2022-01-01 12:01:00", "successful_login"};
    LogEntry entry3 = {"10.0.0.1", "2022-01-02 12:00:00", "failed_login"};
    LogEntry entry4 = {"10.0.0.1", "2022-01-02 12:01:00", "failed_login"};
    LogEntry entry5 = {"10.0.0.1", "2022-01-02 12:02:00", "failed_login"};
    log_entries[num_log_entries++] = entry1;
    log_entries[num_log_entries++] = entry2;
    log_entries[num_log_entries++] = entry3;
    log_entries[num_log_entries++] = entry4;
    log_entries[num_log_entries++] = entry5;
    
    // Process the log entries
    for (int i = 0; i < num_log_entries; i++) {
        process_log_entry(&log_entries[i], suspicious_ips, &num_suspicious_ips);
    }
    
    return 0;
}