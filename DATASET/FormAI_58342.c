//FormAI DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOGS 1000
#define MAX_LOG_LENGTH 100

void log_event(char *event)
{
    FILE *log_file;
    char timestamp[20];
    time_t now = time(NULL);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    log_file = fopen("event_log.txt", "a");

    if (log_file == NULL)
    {
        printf("Error: could not open event log file.\n");
        return;
    }

    fprintf(log_file, "%s: %s\n", timestamp, event);
    fclose(log_file);
}

int main(int argc, char *argv[])
{
    char event[MAX_LOG_LENGTH];
    int num_logs = 0;

    printf("\nThis program logs system events.\n");

    while (num_logs < MAX_LOGS)
    {
        printf("\nEnter an event to log (or enter 'q' to quit):\n");
        fgets(event, MAX_LOG_LENGTH, stdin);

        if (event[0] == 'q')
        {
            printf("Quitting event logger.\n");
            break;
        }

        event[strcspn(event, "\n")] = 0; // remove newline character

        if (strlen(event) == 0)
        {
            printf("Error: event description cannot be empty.\n");
            continue;
        }

        log_event(event);
        printf("Event logged!\n");
        num_logs++;
    }

    if (num_logs == MAX_LOGS)
    {
        printf("Maximum number of logs reached.\n");
    }

    return 0;
}