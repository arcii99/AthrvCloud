//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LINE_LENGTH 256
#define MAX_IP_LENGTH 16

struct LogEntry {
    char ip[MAX_IP_LENGTH];
    char message[MAX_LINE_LENGTH];
};

struct SuspiciousIP {
    char ip[MAX_IP_LENGTH];
    int count;
};

int main() {
    struct LogEntry log[MAX_LOG_ENTRIES];
    struct SuspiciousIP suspicious[MAX_LOG_ENTRIES];
    int logCount = 0;
    int suspiciousCount = 0;

    // Read the log entries
    FILE *logFile = fopen("log.txt", "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, logFile)) {
        // Parse the IP address
        char *ipStart = strchr(line, '[') + 1;
        char *ipEnd = strchr(ipStart, ']');
        strncpy(log[logCount].ip, ipStart, ipEnd - ipStart);
        log[logCount].ip[ipEnd - ipStart] = '\0';

        // Parse the message
        char *messageStart = strchr(ipEnd, ' ') + 1;
        strcpy(log[logCount].message, messageStart);

        // Detect and record suspicious IP addresses
        int found = 0;
        for (int i = 0; i < suspiciousCount; i++) {
            if (strcmp(log[logCount].ip, suspicious[i].ip) == 0) {
                found = 1;
                suspicious[i].count++;
                break;
            }
        }
        if (!found) {
            strcpy(suspicious[suspiciousCount].ip, log[logCount].ip);
            suspicious[suspiciousCount].count = 1;
            suspiciousCount++;
        }

        logCount++;
    }
    fclose(logFile);

    // Print suspicious IP addresses and their counts
    for (int i = 0; i < suspiciousCount; i++) {
        if (suspicious[i].count > 10) {
            printf("Suspicious IP address: %s (count: %d)\n", suspicious[i].ip, suspicious[i].count);
        }
    }

    return 0;
}