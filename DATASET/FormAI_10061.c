//FormAI DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <time.h>

void logEvent(char* event, char* message) {
    FILE *logFile = fopen("event-log.txt", "a");
    time_t rawTime;
    struct tm *timeInfo;
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    fprintf(logFile, "[%02d-%02d-%d %02d:%02d:%02d] [%s]: %s\n", 
            timeInfo->tm_mday, timeInfo->tm_mon+1, timeInfo->tm_year+1900,
            timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec, event, message);
    fclose(logFile);
}

int main() {
    printf("Welcome to our C system event logger program!\n\n");

    printf("What event do you want to log?\n");
    char event[50];
    scanf("%s", event);

    printf("Enter the log message: \n");
    char message[1000];
    scanf("\n%[^\n]", message);

    logEvent(event, message);
    printf("\nEvent logged successfully!\n");
    
    return 0;
}