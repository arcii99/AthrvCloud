//FormAI DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(const char *event) {
    FILE *logFile = fopen("system_log.txt", "a+");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    // Current time
    time_t rawTime;
    struct tm *currentTime;
    time(&rawTime);
    currentTime = localtime(&rawTime);

    // Log event to file
    fprintf(logFile, "%d-%02d-%02d %02d:%02d:%02d - %s\n", 
            (currentTime->tm_year + 1900), currentTime->tm_mon + 1, 
            currentTime->tm_mday, currentTime->tm_hour, currentTime->tm_min, 
            currentTime->tm_sec, event);
    fclose(logFile);
}

int main() {
    printf("Log your system events here:\n");
    char event[100];

    do {
        printf("Event: ");
        fgets(event, sizeof(event), stdin);
        logEvent(event);
        printf("Event logged!\n");
    } while (1);

    return 0;
}