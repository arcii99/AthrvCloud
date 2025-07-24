//FormAI DATASET v1.0 Category: System event logger ; Style: minimalist
#include <stdio.h>
#include <time.h>

int main()
{
    FILE *log_file = fopen("system_log.txt", "a"); // Open log file in append mode
    time_t current_time;
    struct tm *time_info;
    char time_string[50];

    if (log_file == NULL)
    {
        printf("Error opening log file!");
        return 1; // Exit program with error code
    }

    current_time = time(NULL); // Get current time
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    fprintf(log_file, "[%s] System event: Program started\n", time_string); // Log program start event

    // Perform system event logging here

    current_time = time(NULL);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
    fprintf(log_file, "[%s] System event: Program ended\n", time_string); // Log program end event

    fclose(log_file); // Close log file
    return 0; // Exit program with success code
}