//FormAI DATASET v1.0 Category: System event logger ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE_NAME "system_log.txt" // Define the name of the log file

void log_event(char event_type[], char event_desc[])
{
    FILE *log_fp; // File pointer for the log file
    char timestamp[25]; // String to store current timestamp
    time_t current_time;
    
    // Get the current timestamp
    time(&current_time);
    strftime(timestamp, 25, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Open the log file for appending
    log_fp = fopen(LOG_FILE_NAME, "a");

    // Check if file was opened successfully
    if (log_fp == NULL)
    {
        printf("Error opening log file.");
        exit(1);
    }

    // Write the event details to the log file
    fprintf(log_fp, "[%s] - %s: %s\n", timestamp, event_type, event_desc);
    
    // Close the log file
    fclose(log_fp);
}

int main()
{
    char event_type[20], event_desc[100];
    int input_flag = 0;

    printf("Welcome to the paranoid system event logger!\n\n");

    while(1)
    {
        // Prompt user for event type
        printf("Event Type: ");
        fgets(event_type, 20, stdin);

        // Check for malicious input
        if (strstr(event_type, "/") || strstr(event_type, ";") || strstr(event_type, "'"))
        {
            printf("Invalid input detected. Please input only alphanumeric characters.\n");
            continue;
        }

        // Prompt user for event description
        printf("Event Description: ");
        fgets(event_desc, 100, stdin);

        // Check for malicious input
        if (strstr(event_desc, "/") || strstr(event_desc, ";") || strstr(event_desc, "'"))
        {
            printf("Invalid input detected. Please input only alphanumeric characters.\n");
            continue;
        }

        // Log the event
        log_event(event_type, event_desc);

        // Display success message
        printf("Event logged successfully.\n\n");
    }

    return 0;
}