//FormAI DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <string.h>
#include <time.h>

void logSystemEvent(char* eventType, char* eventDescription);

int main()
{
    char eventType[50];
    char eventDescription[200];
    
    printf("Enter system event type: ");
    fgets(eventType, 50, stdin);

    printf("Enter system event description: ");
    fgets(eventDescription, 200, stdin);

    logSystemEvent(eventType, eventDescription);
    
    return 0;
}

void logSystemEvent(char* eventType, char* eventDescription)
{
    time_t currentTime;
    struct tm* localTime;

    // Get current time
    currentTime = time(NULL);

    // Convert to local time
    localTime = localtime(&currentTime);

    // Open the event log file for appending
    FILE* eventLog = fopen("system_events.log", "a");

    if (eventLog == NULL)
    {
        printf("Error: Unable to open event log file.\n");
        exit(1);
    }

    // Format the log message
    char logMessage[256];
    strftime(logMessage, sizeof(logMessage), "%Y-%m-%d %H:%M:%S", localTime);
    strcat(logMessage, " - ");
    strcat(logMessage, eventType);
    strcat(logMessage, ": ");
    strcat(logMessage, eventDescription);

    // Write the log message to the event log file
    fprintf(eventLog, "%s\n", logMessage);

    // Close the event log file
    fclose(eventLog);

    printf("System event logged successfully!\n");
}