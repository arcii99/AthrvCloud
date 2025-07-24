//FormAI DATASET v1.0 Category: Log analysis ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LOG_LINES 1000 
#define MAX_LINE_LENGTH 200 
#define MAX_NUM_LOGS 50
#define MAX_LOG_TYPE_LENGTH 20 

struct LogMessage{
    char type[MAX_LOG_TYPE_LENGTH];
    char message[MAX_LINE_LENGTH];
    int lineNum;
};

struct Log {
    struct LogMessage messages[MAX_LOG_LINES];
    int numMessages;
};

void initializeLog(struct Log* log) {
    log->numMessages = 0;
}

void addLogMessage(struct Log* log, char* type, char* message, int lineNum) {
    if(log->numMessages < MAX_LOG_LINES) {
        struct LogMessage newMessage;
        strcpy(newMessage.type, type);
        strcpy(newMessage.message, message);
        newMessage.lineNum = lineNum;

        log->messages[log->numMessages] = newMessage;
        log->numMessages++;
    }
}

void displayLogs(struct Log* log) {
    printf("Log Messages:\n");
    for(int i = 0; i < log->numMessages; i++) {
        printf("[%s] Line %d : %s\n", log->messages[i].type, log->messages[i].lineNum, log->messages[i].message);
    }
}

int main() {
    struct Log logs[MAX_NUM_LOGS];
    int numLogs = 0;

    char logFileName[MAX_LINE_LENGTH];
    printf("Enter log file name: ");
    scanf("%s", logFileName);

    FILE* fp = fopen(logFileName, "r");
    if(fp == NULL) {
        printf("Error Opening File.\n");
        return 0;
    }

    char buffer[MAX_LINE_LENGTH];
    int lineNum = 0;

    while(fgets(buffer, MAX_LINE_LENGTH, fp) != NULL && numLogs < MAX_NUM_LOGS) {
        if(strncmp(buffer, "[INFO]", 6) == 0) {
            char message[MAX_LINE_LENGTH];
            strncpy(message, buffer + 7, strlen(buffer) - 8);
            addLogMessage(&logs[numLogs], "INFO", message, lineNum);
        } else if(strncmp(buffer, "[ERROR]", 7) == 0) {
            char message[MAX_LINE_LENGTH];
            strncpy(message, buffer + 8, strlen(buffer) - 9);
            addLogMessage(&logs[numLogs], "ERROR", message, lineNum);
        } else if(strncmp(buffer, "[WARNING]", 9) == 0) {
            char message[MAX_LINE_LENGTH];
            strncpy(message, buffer + 10, strlen(buffer) - 11);
            addLogMessage(&logs[numLogs], "WARNING", message, lineNum);
        } else {
            addLogMessage(&logs[numLogs], "OTHER", buffer, lineNum);
        }

        if(buffer[strlen(buffer) - 1] == '\n') {
            lineNum++;
        }

        if(buffer[0] == '/' && buffer[1] == '/') {
            numLogs++;
            initializeLog(&logs[numLogs]);
            lineNum = 0;
        }
    }

    fclose(fp);

    printf("%d Logs Found in the file.\n\n", numLogs);

    for(int i = 0; i < numLogs; i++) {
        printf("Log %d:\n", i+1);
        displayLogs(&logs[i]);
        printf("\n");
    }

    return 0;
}