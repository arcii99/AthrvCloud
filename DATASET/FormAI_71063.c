//FormAI DATASET v1.0 Category: System event logger ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(const char* eventName, int eventLevel, FILE* logFile) {
    time_t now = time(NULL);
    struct tm currentTime = *localtime(&now);

    fprintf(logFile, "[%02d-%02d-%d %02d:%02d:%02d] [%d] %s\n", 
            currentTime.tm_mday, currentTime.tm_mon + 1, currentTime.tm_year + 1900, 
            currentTime.tm_hour, currentTime.tm_min, currentTime.tm_sec,
            eventLevel, eventName);
}

void logSystemEvent(const char* eventName, int eventLevel) {
    FILE* logFile = fopen("system.log", "a");
    if (logFile == NULL) {
        printf("Error: Could not open system.log file\n");
        return;
    }

    logEvent(eventName, eventLevel, logFile);
    fclose(logFile);

    if (eventLevel >= 5) {
        printf("Critical error event detected! Exiting...\n");
        exit(1); // terminate program
    }
}

void testLogger(int level) {
    char eventName[50];
    sprintf(eventName, "Test event: Level %d", level);
    logSystemEvent(eventName, level);
    if (level > 0) {
        testLogger(level - 1);
    }
}

int main() {
    for (int i = 10; i >= 0; i--) {
        testLogger(i);
    }
    return 0;
}