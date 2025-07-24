//FormAI DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
    const char *filename = "eventlog.txt";
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s for appending.\n", filename);
        exit(EXIT_FAILURE);
    }

    time_t current_time = time(NULL); // Get the current time
    char *time_string = ctime(&current_time); // Convert the time to string format for logging
    if (time_string[strlen(time_string)-1] == '\n') { // Remove the newline character at the end of the time string
        time_string[strlen(time_string)-1] = '\0';
    }

    fprintf(file, "[%s] The system has started.\n", time_string); // Log the system starting event

    // Simulate some system events
    for (int i = 0; i < 10; i++) {
        current_time = time(NULL);
        time_string = ctime(&current_time);
        if (time_string[strlen(time_string)-1] == '\n') {
            time_string[strlen(time_string)-1] = '\0';
        }
        fprintf(file, "[%s] System event %d has occurred.\n", time_string, i);
    }

    current_time = time(NULL);
    time_string = ctime(&current_time);
    if (time_string[strlen(time_string)-1] == '\n') {
        time_string[strlen(time_string)-1] = '\0';
    }

    fprintf(file, "[%s] The system is shutting down.\n", time_string); // Log the system shutting down event

    fclose(file);

    return 0;
}