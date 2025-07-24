//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LOGS 1000 // Maximum number of logs to store
#define MAX_IP_LEN 16 // Maximum length of an IP address string
#define MAX_TIME_LEN 20 // Maximum length of a timestamp string

typedef struct LogEntry {
    char ip[MAX_IP_LEN];
    char time[MAX_TIME_LEN];
} LogEntry;

bool isBlacklisted(char *ip, LogEntry *logs, int num_logs) {
    int count = 0;
    for (int i = 0; i < num_logs; i++) {
        if (strcmp(logs[i].ip, ip) == 0) {
            count++;
        }
        if (count >= 10) {
            return true;
        }
    }
    return false;
}

int main() {
    LogEntry logs[MAX_LOGS];
    int num_logs = 0;
    char input[100];

    printf("Enter a log entry (IP and timestamp separated by a space), or type \"quit\" to exit:\n");

    while (true) {
        fgets(input, 100, stdin);
        if (strncmp(input, "quit", 4) == 0) {
            break;
        }
        char *ip = strtok(input, " ");
        char *time = strtok(NULL, " ");
        if (ip == NULL || time == NULL) {
            printf("Invalid input, please try again\n");
            continue;
        }
        // Remove newline character from end of time string
        time[strcspn(time, "\n")] = 0;

        if (isBlacklisted(ip, logs, num_logs)) {
            printf("Intrusion detected from IP address: %s\n", ip);
        } else {
            printf("No intrusion detected\n");
            strcpy(logs[num_logs].ip, ip);
            strcpy(logs[num_logs].time, time);
            num_logs++;
        }
    }

    return 0;
}