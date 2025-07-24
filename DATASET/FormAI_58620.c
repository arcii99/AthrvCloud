//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LOG_SIZE 100000

typedef struct {
    char *timestamp;
    char *event_type;
    char *src_ip;
    char *dest_ip;
} log_entry;

void log_event(log_entry entry, log_entry *log, int *current_size) {
    if (*current_size == MAX_LOG_SIZE) {
        printf("Log is full!");
        return;
    }
    log[*current_size] = entry;
    *current_size += 1;
    printf("Event logged successfully!");
}

void detect_intrusion(log_entry *log, int size) {
    int count_failed_login = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(log[i].event_type, "login") == 0 && strcmp(log[i].dest_ip, "192.168.1.1") != 0) {
            count_failed_login += 1;
        }
        if (count_failed_login >= 3) {
            printf("Intrusion detected!");
            return;
        }
    }
    printf("No intrusion detected");
}

int main() {
    log_entry log[MAX_LOG_SIZE];
    int current_size = 0;

    log_entry entry1 = {"2021-09-01 10:20:30", "login", "192.168.1.2", "192.168.1.1"};
    log_event(entry1, log, &current_size);

    log_entry entry2 = {"2021-09-01 10:21:30", "login", "192.168.1.3", "192.168.1.1"};
    log_event(entry2, log, &current_size);

    log_entry entry3 = {"2021-09-01 10:22:30", "login", "192.168.1.4", "192.168.1.1"};
    log_event(entry3, log, &current_size);

    detect_intrusion(log, current_size);

    log_entry entry4 = {"2021-09-01 10:23:30", "login", "192.168.1.5", "192.168.1.1"};
    log_event(entry4, log, &current_size);

    detect_intrusion(log, current_size);

    return 0;
}