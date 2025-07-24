//FormAI DATASET v1.0 Category: System event logger ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// define the maximum length of each log message
#define MAX_LOG_LENGTH 256

// define the maximum number of logs that can be stored
#define MAX_LOGS 10000

// define the maximum length of the log file path
#define MAX_FILE_PATH_LENGTH 256

// define the log level constants
#define INFO 0
#define WARNING 1
#define ERROR 2

// define a struct to represent a single log message
typedef struct {
    time_t timestamp;
    int level;
    char message[MAX_LOG_LENGTH];
} LogMessage;

// define a struct to represent the event logger
typedef struct {
    bool initialized;
    LogMessage logs[MAX_LOGS];
    int num_logs;
    char log_file_path[MAX_FILE_PATH_LENGTH];
} EventLogger;

// initialize the event logger
void initLogger(EventLogger* logger, char* log_file_path) {
    logger->initialized = true;
    logger->num_logs = 0;
    strcpy(logger->log_file_path, log_file_path);
}

// log a message with the given level
void logMessage(EventLogger* logger, int level, char* message) {
    // make sure the logger has been initialized
    if (!logger->initialized) {
        printf("Error: logger has not been initialized!\n");
        exit(1);
    }
    
    // make sure the level is valid
    if (level != INFO && level != WARNING && level != ERROR) {
        printf("Error: invalid log level!\n");
        exit(1);
    }
    
    // make sure the message is not too long
    if (strlen(message) >= MAX_LOG_LENGTH) {
        printf("Error: log message is too long!\n");
        exit(1);
    }
    
    // create a new log message
    LogMessage new_log;
    new_log.timestamp = time(NULL);
    new_log.level = level;
    strcpy(new_log.message, message);
    
    // add the new log to the logger's list of logs
    logger->logs[logger->num_logs] = new_log;
    logger->num_logs++;
    
    // if the logger's list of logs is full, write them to the log file
    if (logger->num_logs >= MAX_LOGS) {
        FILE* log_file = fopen(logger->log_file_path, "a");
        for (int i = 0; i < logger->num_logs; i++) {
            char log_level_str[32];
            switch (logger->logs[i].level) {
                case INFO:
                    strcpy(log_level_str, "INFO");
                    break;
                case WARNING:
                    strcpy(log_level_str, "WARNING");
                    break;
                case ERROR:
                    strcpy(log_level_str, "ERROR");
                    break;
            }
            fprintf(log_file, "[%s] %s - %s\n", log_level_str, ctime(&logger->logs[i].timestamp), logger->logs[i].message);
        }
        fclose(log_file);
        logger->num_logs = 0;
    }
}

// main function for testing
int main() {
    // initialize the logger
    EventLogger logger;
    initLogger(&logger, "example.log");
    
    // log some messages
    logMessage(&logger, INFO, "Program started.");
    logMessage(&logger, WARNING, "Unexpected input detected.");
    logMessage(&logger, ERROR, "File could not be opened.");
    logMessage(&logger, INFO, "Program ended.");
    
    return 0;
}