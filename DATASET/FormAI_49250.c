//FormAI DATASET v1.0 Category: System event logger ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This program logs system events into a file
 * each time an event occurs, the program will capture 
 * the current system time and log it along with the 
 * event message into a file.
*/

static const char* logFilePath = "events.log";

void logEvent(const char* message) {
    FILE* logFile = fopen(logFilePath, "a");

    if(logFile == NULL) {
        printf("Failed to open log file. Aborting...\n");
        exit(-1);
    }

    // get current system time
    time_t rawTime;
    struct tm* timeInfo;
    char timeBuff[64];

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(timeBuff, sizeof(timeBuff), "%Y-%m-%d %H:%M:%S", timeInfo);

    // write log message
    fprintf(logFile, "[%s] %s\n", timeBuff, message);

    fclose(logFile);
}

int main() {
    logEvent("System started");

    // do something here

    logEvent("System paused");

    // do something here

    logEvent("System resumed");

    // do something here

    logEvent("System stopped");

    return 0;
}