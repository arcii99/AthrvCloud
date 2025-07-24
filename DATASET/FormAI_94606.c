//FormAI DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *message, char *logFilePath) {
    time_t currentTime;
    struct tm *localTime;
    FILE *logFile;
 
    char currentDatetime[64];
    
    // get current datetime in ISO format
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    strftime(currentDatetime, sizeof(currentDatetime), "%Y-%m-%dT%H:%M:%S", localTime);
 
    // open log file in append mode
    logFile = fopen(logFilePath, "a+");
    if (logFile == NULL) {
        printf("Error: Unable to open log file for writing\n");
        return;
    }
    
    // write log message to file with datetime
    fprintf(logFile, "[%s] %s\n", currentDatetime, message);
    
    // close log file
    fclose(logFile);
}

int main() {
    printf("System Event Logger\n");
    
    char message[256];
    char logFilePath[] = "./system.log";
    
    // log a welcome message
    sprintf(message, "System event logger started");
    logEvent(message, logFilePath);
    
    // simulate a system event
    sprintf(message, "Network interface failure");
    logEvent(message, logFilePath);
    
    // simulate another system event
    sprintf(message, "Disk space low");
    logEvent(message, logFilePath);
    
    // log a farewell message
    sprintf(message, "System event logger stopped");
    logEvent(message, logFilePath);
    
    printf("Events logged to %s\n", logFilePath);
    
    return 0;
}