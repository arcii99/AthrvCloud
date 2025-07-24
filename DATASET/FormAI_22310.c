//FormAI DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_LOG_FILE "event.log"    // Define the log file name

void log_event(const char* message)
{
    FILE* f = fopen(EVENT_LOG_FILE, "a");    // Open the log file in append mode
    if (f == NULL) {
        printf("Error opening log file! Aborting.\n");
        exit(EXIT_FAILURE);
    }

    time_t current_time = time(NULL);
    char* timestamp = ctime(&current_time);  // Get the current time and format it
    timestamp[strlen(timestamp)-1] = '\0';   // Remove the newline character from the end

    fprintf(f, "%s - %s\n", timestamp, message);   // Write the log message to the log file
    fclose(f);  // Close the log file
}

int main(void)
{
    // Simulate some events
    log_event("System started up");
    log_event("User login successful");
    log_event("File saved");

    printf("Events logged to %s\n", EVENT_LOG_FILE);
    return 0;
}