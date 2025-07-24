//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_IP_LENGTH 15

struct LogEntry {
    char ip[MAX_IP_LENGTH];
    char message[100];
};

struct LogEntry logEntries[MAX_LOG_ENTRIES];
int numEntries = 0;

void logMessage(char *ip, char *message) {
    if (numEntries == MAX_LOG_ENTRIES) {
        fprintf(stderr, "Too many log entries!\n");
        exit(1);
    }
    struct LogEntry newEntry;
    strncpy(newEntry.ip, ip, MAX_IP_LENGTH);
    strncpy(newEntry.message, message, 100);
    logEntries[numEntries++] = newEntry;
}

int main() {
    char *ip = "192.168.1.1";
    char *message = "Unauthorized access attempt";
    logMessage(ip, message);
    char *ip2 = "10.0.0.2";
    char *message2 = "Invalid password attempt";
    logMessage(ip2, message2);

    // count number of log entries for each IP address
    int numEntriesPerIp[MAX_LOG_ENTRIES] = {0};
    for (int i = 0; i < numEntries; i++) {
        struct LogEntry entry = logEntries[i];
        char *ip = entry.ip;
        numEntriesPerIp[i] += 1; 
    }

    // detect potential intrusion by checking for multiple log entries from one IP
    for (int i = 0; i < numEntries; i++) {
        if (numEntriesPerIp[i] > 5) {
            printf("Potential intrusion detected from IP address: %s\n", logEntries[i].ip);
        }
    }

    return 0;
}