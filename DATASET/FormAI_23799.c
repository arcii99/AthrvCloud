//FormAI DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num_logs = 1000;
    FILE *log_file;
    log_file = fopen("server_logs.txt", "r");
    char log_message[num_logs][200];
    int log_count = 0;

    if (log_file == NULL)
    {
        printf("Error: Unable to open server_logs.txt\n");
        exit(1);
    }
    
    // Reading log messages from file
    while (fgets(log_message[log_count], 200, log_file))
    {
        log_count++;
    }

    // Closing the log file
    fclose(log_file);

    // Displaying log messages with warnings
    for (int i = 0; i < log_count; i++)
    {
        if (strstr(log_message[i], "WARNING") != NULL)
        {
            printf("WARNING at %d: %s\n", i+1, log_message[i]);
        }
    }

    // Displaying log messages with errors
    for (int i = 0; i < log_count; i++)
    {
        if (strstr(log_message[i], "ERROR") != NULL)
        {
            printf("ERROR at %d: %s\n", i+1, log_message[i]);
        }
    }

    // Displaying log messages with successful operations
    for (int i = 0; i < log_count; i++)
    {
        if (strstr(log_message[i], "SUCCESS") != NULL)
        {
            printf("SUCCESS at %d: %s\n", i+1, log_message[i]);
        }
    }

    return 0;
}