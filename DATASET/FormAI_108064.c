//FormAI DATASET v1.0 Category: System event logger ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(const char* event)
{
    FILE *fp;
    time_t current_time;

    current_time = time(NULL);

    fp = fopen("event.log", "a");
    if(fp == NULL)
    {
        printf("Failed to open event.log\n");
        return;
    }

    fprintf(fp, "%s: %s\n", ctime(&current_time), event);

    fclose(fp);
}

int main()
{
    printf("Welcome to the Peaceful Logger!\n\n");

    while(1)
    {
        char event[100];

        printf("Enter an event to log (or 'q' to quit):");
        fgets(event, 100, stdin);

        if(event[0] == 'q')
        {
            break;
        }

        log_event(event);

        printf("Event logged!\n\n");
    }

    printf("Thank you for using the Peaceful Logger.\n");

    return 0;
}