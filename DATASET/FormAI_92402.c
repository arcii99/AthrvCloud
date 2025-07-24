//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 10000
#define MAX_SUSPICIOUS_EVENTS 3

typedef struct {
    int id;
    char* timestamp;
    char* event;
} Log;

typedef struct {
    int id;
    int count;
} EventCounter;

Log logs[MAX_LOG_SIZE];
EventCounter suspiciousEvents[MAX_SUSPICIOUS_EVENTS];

int currentLogIndex = 0;
int currentSuspiciousEventIndex = 0;

void logEvent(char* event) {
    time_t t = time(NULL);
    struct tm* local_time = localtime(&t);
    char* timestamp = asctime(local_time);
    logs[currentLogIndex].id = currentLogIndex;
    logs[currentLogIndex].timestamp = timestamp;
    logs[currentLogIndex].event = event;
    currentLogIndex++;
}

void printLog(int id) {
    if (id >= 0 && id < currentLogIndex) {
        printf("ID: %d, Timestamp: %s, Event: %s\n", logs[id].id, logs[id].timestamp, logs[id].event);
    }
}

void printAllLogs() {
    for (int i = 0; i < currentLogIndex; i++) {
        printLog(i);
    }
}

void checkSuspiciousEvents() {
    for (int i = 0; i < currentLogIndex; i++) {
        if (strcmp(logs[i].event, "Unauthorized access attempted") == 0) {
            int j;
            for (j = 0; j < currentSuspiciousEventIndex; j++) {
                if (suspiciousEvents[j].id == i) {
                    suspiciousEvents[j].count++;
                    break;
                }
            }
            if (j == currentSuspiciousEventIndex) {
                suspiciousEvents[currentSuspiciousEventIndex].id = i;
                suspiciousEvents[currentSuspiciousEventIndex].count = 1;
                currentSuspiciousEventIndex++;
            }
        }
    }
}

int main() {
    logEvent("User login successful");
    logEvent("File accessed");
    logEvent("Unauthorized access attempted");
    logEvent("Unauthorized access attempted");
    logEvent("File deleted");
    logEvent("Unauthorized access attempted");
    logEvent("User logout successful");

    checkSuspiciousEvents();

    printf("All logs:\n");
    printAllLogs();

    printf("\nSuspicious events:\n");
    for (int i = 0; i < currentSuspiciousEventIndex; i++) {
        printLog(suspiciousEvents[i].id);
        printf("Count: %d\n\n", suspiciousEvents[i].count);
    }

    return 0;
}