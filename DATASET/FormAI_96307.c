//FormAI DATASET v1.0 Category: Log analysis ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

typedef struct log_entry {
    char* timestamp;
    char* message;
} LogEntry;

LogEntry* logs[MAX_LOG_ENTRIES];
int num_logs = 0;

void addLog(char* timestamp, char* message) {
    if(num_logs >= MAX_LOG_ENTRIES) {
        printf("Error: log full\n");
        return;
    }
    LogEntry* new_log = malloc(sizeof(LogEntry));
    new_log->timestamp = malloc(strlen(timestamp) + 1);
    strcpy(new_log->timestamp, timestamp);
    new_log->message = malloc(strlen(message) + 1);
    strcpy(new_log->message, message);
    logs[num_logs++] = new_log;
}

void printLogs() {
    printf("Logs:\n");
    for(int i = 0; i < num_logs; i++) {
        printf("%s - %s\n", logs[i]->timestamp, logs[i]->message);
    }
}

int main() {
    addLog("10:00:01", "System started");
    addLog("10:01:02", "Error: memory allocation failed");
    addLog("10:02:05", "User logged in");
    addLog("10:05:27", "System shutdown");

    printLogs();
    
    return 0;
}