//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_IP_LENGTH 16
#define MAX_LOGS 1000

char* logs[MAX_LOGS];
int logsCount = 0;

int isMalicious(char* ip) {
    for(int i = 0; ip[i] != '\0'; i++) {
        if(ip[i] < '0' || ip[i] > '9') {
            return 1;
        }
    }
    return 0;
}

void logData(char* data) {
    if(logsCount >= MAX_LOGS) {
        printf("Log limit reached. Intrusion detection system shutting down.\n");
        exit(1);
    }
    logs[logsCount++] = data;
}

void analyzeData() {
    for(int i = 0; i < logsCount; i++) {
        char* log = logs[i];
        char* ip = strtok(log, " ");
        if(isMalicious(ip)) {
            printf("WARNING! Malicious IP detected: %s\n", ip);
        }
    }
}

int main() {
    char ip[MAX_IP_LENGTH];
    printf("Enter IP address (q to quit): ");
    scanf("%s", ip);
    while(ip[0] != 'q') {
        logData(ip);
        printf("Enter IP address (q to quit): ");
        scanf("%s", ip);
    }
    analyzeData();
    return 0;
}