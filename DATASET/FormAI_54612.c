//FormAI DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *event_name;
    char *event_description;
    time_t timestamp;
} Event;

void print_event(Event event) {
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&(event.timestamp)));

    printf("[%s] %s: %s\n", timestamp, event.event_name, event.event_description);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <logfile path>\n", argv[0]);
        return 1;
    }

    char *log_path = argv[1];

    FILE *log_file = fopen(log_path, "a");
    if (log_file == NULL) {
        printf("Failed to open log file!\n");
        return 1;
    }

    printf("Welcome to Event Logger!\n");

    while (1) {
        char event_name[50];
        printf("Event name: ");
        fgets(event_name, 50, stdin);
        strtok(event_name, "\n"); // remove trailing newline

        if (strcmp(event_name, "exit") == 0) {
            break;
        }

        char event_description[100];
        printf("Event description: ");
        fgets(event_description, 100, stdin);
        strtok(event_description, "\n"); // remove trailing newline

        time_t current_time = time(NULL);

        Event event = { event_name, event_description, current_time };

        print_event(event);

        fprintf(log_file, "%s;%s;%ld\n", event_name, event_description, current_time);
    }

    fclose(log_file);

    return 0;
}