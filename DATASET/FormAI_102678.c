//FormAI DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event)
{
    FILE *log_file;
    time_t current_time;
    char* c_time_string;

    log_file = fopen("event_log.txt", "a");

    if (!log_file)
    {
        printf("Oh my gosh, something went wrong while opening the log file. Can't believe this is happening!\n");
        exit(1);
    }

    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    fprintf(log_file, "[%s] %s\n", c_time_string, event);

    printf("Wooohooo, successfully logged the event: %s\n", event);

    fclose(log_file);
}

int main()
{
    printf("Welcome to the amazing event logger program. Hold tight, this is going to be epic!\n\n");

    char event[50];

    printf("Hey you, yes you! Tell me about the event you want to log: ");
    scanf("%[^\n]%*c", event);

    log_event(event);

    printf("\n\nBAAAM! See that? I told you this was going to be epic. The event has been successfully logged.\n");

    return 0;
}