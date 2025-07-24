//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRY 1000
#define ATTACK_THRESHOLD 10

typedef struct LogEntry {
    char timestamp[50];
    char ip[20];
    char message[100];
} LogEntry;

int main() {
    LogEntry log[MAX_LOG_ENTRY];
    int logCount = 0;
    int attackCount = 0;
    char input[100];

    while (1) {
        printf("Enter log entry (or exit to quit): ");
        fgets(input, 100, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        LogEntry newLog;
        strcpy(newLog.timestamp, "2022-06-15 15:32:00"); // fake timestamp
        sscanf(input, "%s %s %[^\n]", newLog.ip, newLog.message);
        
        log[logCount++] = newLog;
        if (logCount == MAX_LOG_ENTRY) {
            printf("Log limit reached. Clearing logs.\n");
            logCount = 0;
        }

        int i;
        for (i = logCount - 1; i >= 0; i--) {
            if (strcmp(log[i].ip, newLog.ip) == 0) {
                printf("Possible intruder detected. Last message: %s\n", log[i].message);
                attackCount++;
                if (attackCount >= ATTACK_THRESHOLD) {
                    printf("Intrusion detected from IP: %s\n", newLog.ip);
                    exit(0);
                }
            }
            else {
                break;
            }
        }
    }

    return 0;
}