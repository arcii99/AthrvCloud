//FormAI DATASET v1.0 Category: System event logger ; Style: visionary
// A Unique C System Event Logger Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Creating a file pointer to open the log file
    FILE *log_file = fopen("event_log.txt", "a");

    // Checking if the log file has been opened successfully
    if(log_file == NULL) {
        printf("Error: Unable to open file!");
        return 1;
    }

    // Getting the current time
    time_t now = time(NULL);

    // Storing the current time in a string
    char str_time[25];
    strftime(str_time, 25, "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Prompt the user for the event message
    char event_message[100];
    printf("Enter the event message: ");
    gets(event_message);

    // Writing the event message to the log file
    fprintf(log_file, "%s: %s\n", str_time, event_message);

    // Closing the log file
    fclose(log_file);

    return 0;
}