//FormAI DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// custom log event struct
typedef struct {
    time_t timestamp;
    char *event_type;
    char *description;
} log_event;

// helper function to get current time string
char *get_time_string() {
    time_t current_time;
    time(&current_time);
    return strtok(ctime(&current_time), "\n");
}

// helper function to log the event to file
void log_event_to_file(log_event event) {
    FILE *file_ptr;
    char *filename = "system_logs.txt";
    char *time_string = get_time_string();
    if ((file_ptr = fopen(filename, "a")) == NULL) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    fprintf(file_ptr, "[%s] %s - %s\n", time_string, event.event_type, event.description);
    fclose(file_ptr);
}

int main() {
    log_event event;
    event.timestamp = time(NULL);
    event.event_type = "System Shutdown";
    event.description = "The system was shut down gracefully.";

    log_event_to_file(event);

    return 0;
}