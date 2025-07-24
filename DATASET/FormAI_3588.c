//FormAI DATASET v1.0 Category: System event logger ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *fp;
    char filename[50];
    time_t current_time;
    struct tm * time_info;
    char time_string[50];
    char event[100];

    printf("Enter a filename for the log: ");
    scanf("%s", filename);

    fp = fopen(filename, "a");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    while(1)
    {
        printf("Enter an event to log (or type 'exit' to quit): ");
        scanf("%s", event);

        if(strcmp(event, "exit") == 0)
        {
            break;
        }

        current_time = time(NULL);
        time_info = localtime(&current_time);
        strftime(time_string, sizeof(time_string), "%c", time_info);

        fprintf(fp, "%s - %s\n", time_string, event);

        printf("Event logged successfully!\n");
    }

    fclose(fp);

    printf("Log file saved as %s\n", filename);

    return 0;
}