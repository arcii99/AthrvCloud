//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ip[16];
    char protocol[10];
    char message[100];
} LogEntry;

int isSuspicious(char* message) {
    char* keywords[] = {"root", "sudo", "hack", "attack", "password", "admin"};
    int num_keywords = 6;
    for(int i=0; i<num_keywords; i++) {
        if(strstr(message, keywords[i])) {
            return 1;
        }
    }
    return 0;
}

void logMessage(LogEntry* logEntry) {
    FILE* fp;
    fp = fopen("logs.txt", "a");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(fp, "%s|%s|%s\n", logEntry->ip, logEntry->protocol, logEntry->message);
    fclose(fp);
}

int main() {
    LogEntry logEntry;
    char choice[10];
    do {
        printf("Enter IP address: ");
        fgets(logEntry.ip, 16, stdin);
        logEntry.ip[strcspn(logEntry.ip, "\n")] = 0;
        printf("Enter protocol (HTTP, FTP, SSH, etc.): ");
        fgets(logEntry.protocol, 10, stdin);
        logEntry.protocol[strcspn(logEntry.protocol, "\n")] = 0;
        printf("Enter message: ");
        fgets(logEntry.message, 100, stdin);
        logEntry.message[strcspn(logEntry.message, "\n")] = 0;

        if(isSuspicious(logEntry.message)) {
            printf("ALERT: Suspicious message detected!\n");
        }
        logMessage(&logEntry);
        printf("Do you want to enter another log? (y/n): ");
        fgets(choice, 10, stdin);
    } while(choice[0] == 'y' || choice[0] == 'Y');

    return 0;
}