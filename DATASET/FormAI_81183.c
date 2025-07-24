//FormAI DATASET v1.0 Category: System event logger ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maximal length of log message
#define MAX_LOG_MSG_LEN 1024

// Define the log levels
typedef enum LogLevel {
    ERROR = 0,
    WARNING = 1,
    INFO = 2
} LogLevel;

// Define a struct for the log messages
typedef struct LogMessage {
    LogLevel level;
    char message[MAX_LOG_MSG_LEN];
    time_t timestamp;
} LogMessage;

// Define a function that returns the current timestamp
time_t getCurrentTimestamp() {
    time_t currentTime;
    time(&currentTime);
    return currentTime;
}

// Define a function that creates a log message
LogMessage createLogMessage(LogLevel level, char* message) {
    LogMessage logMsg;
    logMsg.level = level;
    logMsg.timestamp = getCurrentTimestamp();
    strcpy(logMsg.message, message);
    return logMsg;
}

// Define the main function
int main() {
    // Open the log file for writing
    FILE *fp = fopen("event.log", "w");
    if (fp == NULL) {
        printf("Error: could not open log file for writing\n");
        exit(1);
    }

    // Log some messages
    LogMessage msg;
    char errorMsg[MAX_LOG_MSG_LEN] = "Could not connect to database";
    msg = createLogMessage(ERROR, errorMsg);
    fprintf(fp, "[%ld] ERROR - %s\n", msg.timestamp, msg.message);

    char warningMsg[MAX_LOG_MSG_LEN] = "Low disk space";
    msg = createLogMessage(WARNING, warningMsg);
    fprintf(fp, "[%ld] WARNING - %s\n", msg.timestamp, msg.message);

    char infoMsg[MAX_LOG_MSG_LEN] = "User logged in";
    msg = createLogMessage(INFO, infoMsg);
    fprintf(fp, "[%ld] INFO - %s\n", msg.timestamp, msg.message);

    // Close the log file
    fclose(fp);

    return 0;
}