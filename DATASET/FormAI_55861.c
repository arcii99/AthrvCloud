//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_IP_LENGTH 16
#define MAX_MESSAGE_LENGTH 256

typedef struct {
    char ip[MAX_IP_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    time_t timestamp;
} LogEntry;

void scanLogEntries(LogEntry logEntries[], int numEntries) {
    int i, j, count;
    char ip[MAX_IP_LENGTH];
    for(i = 0; i < numEntries; i++) {
        if(strcmp(logEntries[i].message, "Unauthorized access detected") == 0) {
            count = 1;
            strcpy(ip, logEntries[i].ip);
            for(j = i+1; j < numEntries; j++) {
                if(strcmp(logEntries[j].ip, ip) == 0 && strcmp(logEntries[j].message, "Unauthorized access detected") == 0) {
                    count++;
                    if(count == 3) {
                        printf("Intrusion detected from %s at %s\n", ip, ctime(&logEntries[j].timestamp));
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    LogEntry logEntries[MAX_LOG_ENTRIES];
    int numEntries = 0;
    char input[MAX_MESSAGE_LENGTH];
    printf("Welcome to the Intrusion Detection System\n");
    while(numEntries < MAX_LOG_ENTRIES) {
        printf("Enter log message: ");
        fgets(input, MAX_MESSAGE_LENGTH, stdin);
        strtok(input, "\n");
        if(strcmp(input, "exit") == 0) {
            break;
        }
        time_t now = time(NULL);
        LogEntry newEntry;
        strcpy(newEntry.message, input);
        strcpy(newEntry.ip, "10.0.0.1"); //hardcoded IP for testing
        newEntry.timestamp = now;
        logEntries[numEntries] = newEntry;
        numEntries++;
    }
    if(numEntries == MAX_LOG_ENTRIES) {
        printf("Maximum number of log entries reached\n");
    }
    scanLogEntries(logEntries, numEntries);
    return 0;
}