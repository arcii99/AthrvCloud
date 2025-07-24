//FormAI DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *event_type, char *description);

int main()
{
    char event_type[50], description[100];

    printf("Enter event type: ");
    scanf("%s", event_type);

    printf("Enter event description: ");
    scanf("%s", description);

    log_event(event_type, description);

    return 0;
}

void log_event(char *event_type, char *description)
{
    time_t current_time;
    struct tm *time_info;
    char time_string[50];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    FILE *file = fopen("event_log.txt", "a");

    if (file == NULL)
    {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    fprintf(file, "%s %s: %s\n", time_string, event_type, description);

    fclose(file);

    printf("Event logged successfully!\n");
}