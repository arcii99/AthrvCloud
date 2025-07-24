//FormAI DATASET v1.0 Category: System event logger ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *EVENT_TYPES[] = {"WARNING", "ERROR", "INFO", "DEBUG"};

void log_event(char *event_type, char *message)
{
    time_t rawtime;
    struct tm *info;
    char buffer[80];

    time(&rawtime);
    info = localtime(&rawtime);

    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);

    printf("[%s] [%s]: %s\n", buffer, event_type, message);
}

int main()
{
    char *event_message;
    char *event_type;
    int random_event_index;

    srand(time(NULL));

    for (int i = 0; i < 50; i++)
    {
        random_event_index = rand() % 4;

        event_type = EVENT_TYPES[random_event_index];

        switch(random_event_index)
        {
            case 0:
                event_message = "Warning: Disk full";
                break;
            case 1:
                event_message = "Error: Unable to connect to database";
                break;
            case 2:
                event_message = "Info: Application started";
                break;
            case 3:
                event_message = "Debug: User input validated successfully";
                break;
        }

        log_event(event_type, event_message);
    }

    return 0;
}