//FormAI DATASET v1.0 Category: System event logger ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_FILE "event_log.txt"

void log_event(char *event_type, char *message) {
    time_t curr_time;
    struct tm *local_time;
    char time_str[20];
    FILE *event_file;

    // Get the current time
    curr_time = time(NULL);
    local_time = localtime(&curr_time);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local_time);

    // Open the event file in append mode
    event_file = fopen(EVENT_FILE, "a");
    if (event_file == NULL) {
        printf("Failed to open event log file\n");
        return;
    }

    // Write the event to the file
    fprintf(event_file, "%s | %s: %s\n", time_str, event_type, message);

    // Close the file
    fclose(event_file);
}

int main() {
    char event_type[20];
    char message[100];

    printf("Enter event type: ");
    scanf("%s", event_type);

    printf("Enter event message: ");
    scanf(" %[^\n]s", message);

    log_event(event_type, message);

    printf("Event logged successfully\n");

    return 0;
}