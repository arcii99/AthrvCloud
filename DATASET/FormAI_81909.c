//FormAI DATASET v1.0 Category: System event logger ; Style: synchronous
#include <stdio.h>
#include <time.h>

// function to get the current time stamp
char* getTimestamp()
{
    time_t rawtime;
    struct tm * timeinfo;
    char* buffer = (char*) malloc(sizeof(char)*20);
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%Y-%m-%d %H:%M:%S",timeinfo);
    return buffer;
}

// function to log events
void logEvent(char* event)
{
    FILE *fp;
    char* timestamp = getTimestamp();
    fp = fopen("event_log.txt", "a+");
    if(fp != NULL)
    {
        fprintf(fp, "[%s] %s\n", timestamp, event);
        printf("Event \"%s\" logged successfully.\n", event);
        fclose(fp);
    }
    else
    {
        printf("Error: Could not open file for logging.\n");
    }
    free(timestamp);
}

// main function to test event logger
int main()
{
    logEvent("Application started.");

    // simulate some events
    int i;
    for(i=1; i<=5; i++)
    {
        char* event = (char*) malloc(sizeof(char)*50);
        sprintf(event, "Event %d occurred.", i);
        logEvent(event);
        free(event);
    }

    logEvent("Application stopped.");
    return 0;
}