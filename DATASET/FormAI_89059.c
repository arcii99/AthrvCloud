//FormAI DATASET v1.0 Category: System event logger ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_BUFFER_SIZE 1024
#define MAX_EVENT_TYPE_LEN 64

typedef struct {
    char timestamp[32];
    char event_type[MAX_EVENT_TYPE_LEN];
    char message[EVENT_BUFFER_SIZE];
} Event;

// Generate a random timestamp string with format "Year-Month-Day Hour:Minute:Second"
void get_timestamp(char *timestamp) {
    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);
    strftime(timestamp, 32, "%Y-%m-%d %H:%M:%S", tm);
}

int main() {
    FILE *log_file;
    char event_buffer[EVENT_BUFFER_SIZE];

    log_file = fopen("c_event_log.txt", "a");
    if (log_file == NULL) {
        printf("Failed to open log file for writing.\n");
        return EXIT_FAILURE;
    }

    printf("Enter event type:\n");
    fgets(event_buffer, MAX_EVENT_TYPE_LEN, stdin);
    strtok(event_buffer, "\n");  // Remove newline character from input

    Event new_event;
    get_timestamp(new_event.timestamp);

    if (strlen(event_buffer) > MAX_EVENT_TYPE_LEN) {
        printf("Event type exceeds maximum length of %d characters.\n", MAX_EVENT_TYPE_LEN);
        sprintf(new_event.event_type, "Error");
        sprintf(new_event.message, "Event type exceeds maximum length of %d characters.", MAX_EVENT_TYPE_LEN);
    } else {
        sprintf(new_event.event_type, "%s", event_buffer);
        printf("Enter event message:\n");
        fgets(new_event.message, EVENT_BUFFER_SIZE, stdin);

        // Remove newline character from input
        strtok(new_event.message, "\n");
    }

    fprintf(log_file, "Timestamp: %s\nEvent Type: %s\nMessage: %s\n\n",
            new_event.timestamp, new_event.event_type, new_event.message);

    fclose(log_file);

    printf("Event logged successfully:\n%s\n%s\n%s\n", new_event.timestamp,
           new_event.event_type, new_event.message);

    return EXIT_SUCCESS;
}