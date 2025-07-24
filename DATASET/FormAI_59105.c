//FormAI DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <time.h>
#include <string.h>

// System logger function
void log_message(FILE *logfile, char *event, char *timestamp)
{
    if (logfile != NULL)
    {
        fprintf(logfile, "[%s] %s\n", timestamp, event);
        fflush(logfile);
    }
}

int main()
{
    // File pointer for the log file
    FILE *logfile;

    // Open a new log file in append mode
    char filename[] = "system_log.txt";
    logfile = fopen(filename, "a");

    // Check if the log file was opened successfully
    if (logfile == NULL)
    {
        printf("Error: Could not open log file %s\n", filename);
        return 1;
    }

    // Get the current timestamp
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[64];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    // Log some system events
    log_message(logfile, "System started", timestamp);
    log_message(logfile, "Application started", timestamp);
    log_message(logfile, "File saved successfully", timestamp);

    // Close the log file
    fclose(logfile);

    return 0;
}