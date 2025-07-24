//FormAI DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char type[], char message[])
{
    FILE *logFile;
    time_t currentTime;

    // Get the current time and store it in a struct
    currentTime = time(NULL);

    // Open the log file in append mode
    logFile = fopen("events.log", "a");

    // Check if the file was opened successfully
    if (logFile == NULL)
    {
        printf("Unable to open log file!\n");
        exit(1);
    }

    // Write the event message to the log file
    fprintf(logFile, "[%s] %s - %s\n", type, message, ctime(&currentTime));

    // Close the log file
    fclose(logFile);
}

int main()
{
    char eventType[20];
    char eventMessage[100];

    // Get input from the user
    printf("Enter the type of event: ");
    scanf("%s", eventType);
    printf("Enter the event message: ");
    scanf("%s", eventMessage);

    // Log the event
    logEvent(eventType, eventMessage);

    printf("Event logged successfully.");

    return 0;
}