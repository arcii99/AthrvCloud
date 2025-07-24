//FormAI DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_FILE "event_log.txt"

void log_event(char* event_type, char* event_description) {
    time_t current_time;
    char* formatted_time;
    FILE* event_file;

    current_time = time(NULL);
    formatted_time = ctime(&current_time);
    formatted_time[strlen(formatted_time) - 1] = '\0'; // remove newline from formatted time

    event_file = fopen(EVENT_FILE, "a");
    fprintf(event_file, "[%s] %s - %s\n", formatted_time, event_type, event_description);
    fclose(event_file);
}

int main() {
    char event_type[50];
    char event_description[200];

    printf("Enter event type: ");
    fgets(event_type, 50, stdin);
    printf("Enter event description: ");
    fgets(event_description, 200, stdin);

    log_event(event_type, event_description);

    printf("Event logged successfully!\n");

    return 0;
}