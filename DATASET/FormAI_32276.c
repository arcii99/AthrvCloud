//FormAI DATASET v1.0 Category: System event logger ; Style: excited
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    FILE *logfile;
    char event[100];
    struct tm *local_time;
    time_t t;

    // Creating a file to log events
    logfile = fopen("events.log", "a");

    // Checking if the file was created successfully
    if (logfile == NULL)
    {
        printf("Error creating log file. Exiting program.\n");
        exit(1);
    }

    printf("Event Logger program started! \n");

    printf("Enter the events to be logged: \n");
    fgets(event, 100, stdin);

    // Getting current time and formatting it to display in the log
    t = time(NULL);
    local_time = localtime(&t);
    fprintf(logfile, "Event logged at: %02d/%02d/%d %02d:%02d:%02d\tEvent: %s", local_time->tm_mday, local_time->tm_mon + 1,
            local_time->tm_year + 1900, local_time->tm_hour, local_time->tm_min, local_time->tm_sec, event);

    printf("Event logged successfully! \n");

    // Closing the file
    fclose(logfile);

    return 0;
}