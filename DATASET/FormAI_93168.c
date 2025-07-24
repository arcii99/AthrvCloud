//FormAI DATASET v1.0 Category: System event logger ; Style: interoperable
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LENGTH 100

void log_event(char *event_type, char *event_name, char *event_description){
    time_t current_time;
    char *timestamp;
    char log_output[MAX_LOG_LENGTH];

    // Get current time and format it
    current_time = time(NULL);
    timestamp = ctime(&current_time);
    timestamp[strlen(timestamp)-1] = '\0';

    // Format the log message
    snprintf(log_output, MAX_LOG_LENGTH, "%s -- %s: %s - %s\n", timestamp, event_type, event_name, event_description);

    // Write to log file
    FILE *log_file;
    log_file = fopen("events.log", "a");
    fprintf(log_file, "%s", log_output);
    fclose(log_file);
}

int main(){
    char event_type[] = "INFO";
    char event_name[] = "Program Start";
    char event_description[] = "The program has started.";

    log_event(event_type, event_name, event_description);

    return 0;
}