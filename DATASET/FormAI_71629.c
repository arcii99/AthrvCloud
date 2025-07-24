//FormAI DATASET v1.0 Category: System event logger ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventType, char* message);

int main()
{
    char eventType[20];
    char message[100];

    printf("Enter event type: ");
    scanf("%s", eventType);

    printf("Enter message: ");
    scanf("%s", message);

    logEvent(eventType, message);

    return 0;
}

void logEvent(char* eventType, char* message)
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    FILE* logfile = fopen("event_logs.txt", "a");

    if(logfile == NULL)
    {
        printf("Error opening log file.");
        exit(1);
    }

    fprintf(logfile, "[%d-%d-%d %d:%d:%d] %s: %s\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, eventType, message);

    fclose(logfile);
}