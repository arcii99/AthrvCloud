//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LOG_ENTRIES 100

struct log_entry {
    char timestamp[30];
    char source_ip[20];
    char message[100];
};

struct log {
    struct log_entry entries[MAX_LOG_ENTRIES];
    int count;
};

bool is_suspicious(char *ip) {
    // Add your own code to determine if the IP is suspicious
    return false;
}

void add_log_entry(struct log *l, char *timestamp, char *source_ip, char *message) {
    if (l->count >= MAX_LOG_ENTRIES) {
        // Log is full, cannot add any new entries
        return;
    }
    struct log_entry *e = &l->entries[l->count];
    snprintf(e->timestamp, 30, "%s", timestamp);
    snprintf(e->source_ip, 20, "%s", source_ip);
    snprintf(e->message, 100, "%s", message);
    l->count++;
}

void handle_intrusion_detected(char *timestamp, char *source_ip) {
    struct log log;
    log.count = 0;
    add_log_entry(&log, timestamp, source_ip, "INTRUSION DETECTED");
    if (is_suspicious(source_ip)) {
        add_log_entry(&log, timestamp, source_ip, "SUSPICIOUS ACTIVITY DETECTED");
        printf("Attention: suspicious activity detected from IP: %s\n", source_ip);
    }
    // TODO: Add logic to send alert emails or notifications
}

int main() {
    handle_intrusion_detected("2021-09-01 12:00:00", "192.168.0.100");
    return 0;
}