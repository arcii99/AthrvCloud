//FormAI DATASET v1.0 Category: System event logger ; Style: immersive
#include <stdio.h>
#include <time.h>
#include <string.h>

void log_event(char* event) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char log[100];
    sprintf(log, "[%d-%02d-%02d %02d:%02d:%02d] %s\n", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec, event);

    FILE* file = fopen("event_log.txt", "a");
    if (file) {
        fputs(log, file);
        fclose(file);
    }
}

int main() {
    // Welcome Message
    printf("Welcome to the Event Logger!\n");
    printf("This program logs events to a text file named 'event_log.txt'.\n");

    // Start Logging
    while (1) {
        printf("Please type an event to log (or 'exit' to quit): ");
        char event[100];
        fgets(event, 100, stdin);

        // Remove trailing newline character
        event[strcspn(event, "\n")] = 0;

        // Log the event
        if (strcmp(event, "exit") == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        } else {
            log_event(event);
            printf("Event logged: %s\n", event);
        }
    }

    return 0;
}