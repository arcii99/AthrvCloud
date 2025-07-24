//FormAI DATASET v1.0 Category: System event logger ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *event, char* file, int line) {
    time_t currentTime = time(NULL);
    char *timeStr = ctime(&currentTime);
    if (timeStr != NULL) {
        // Remove newline character from the timestamp
        timeStr[strlen(timeStr) - 1] = '\0';
    }

    FILE *logFile;
    logFile = fopen("event.log", "a");
    if (logFile != NULL) {
        fprintf(logFile, "[%s] %s:%d: %s\n", timeStr, file, line, event);
        fclose(logFile);
    }
}

#define log(e) logEvent(e, __FILE__, __LINE__)

int main() {
    printf("Welcome to the event logger program!\n");

    // Log some events
    log("Program started");
    log("Initialized variables");
    log("User clicked button");

    printf("Events logged to file event.log\n");

    return 0;
}