//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000

typedef struct {
    char timestamp[20];
    char message[100];
} log_entry;

log_entry log[MAX_LOG_ENTRIES];
int log_index = 0;

void add_to_log(char *timestamp, char *message) {
    if (log_index < MAX_LOG_ENTRIES) {
        strcpy(log[log_index].timestamp, timestamp);
        strcpy(log[log_index].message, message);
        log_index++;
    } else {
        printf("Log is full, cannot add more entries.\n");
    }
}

void analyze_logs() {
    int i, j;
    for (i = 0; i < log_index; i++) {
        for (j = i+1; j < log_index; j++) {
            if (strcmp(log[i].message, log[j].message) == 0) {
                printf("Intrusion Detected: %s\n", log[i].message);
            }
        }
    }
}

int main() {
    char timestamp[20], message[100];
    printf("Enter log entries in the format: timestamp message\n");
    printf("Enter 'quit' to exit.\n");
    while (1) {
        scanf("%s", timestamp);
        if (strcmp(timestamp, "quit") == 0) {
            break;
        }
        scanf("%[^\n]", message);
        add_to_log(timestamp, message);
    }
    analyze_logs();
    return 0;
}