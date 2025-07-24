//FormAI DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Struct to hold each event that is logged
typedef struct {
    char* timestamp;
    char* event_type;
    char* event_message;
} SystemEvent;

// Function to print the event log in a readable format
void printLog(SystemEvent** log, int num_events) {
    printf("System Event Log:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s\t%s\t%s\n", log[i]->timestamp, log[i]->event_type, log[i]->event_message);
    }
}

int main() {
    // Initialize the event log and necessary variables
    SystemEvent** log = (SystemEvent**) malloc(sizeof(SystemEvent*));
    int num_events = 0;
    int max_events = 1;
    char buffer[100];

    // Print a welcome message
    printf("Welcome to the System Event Logger!\n");

    // Loop to allow the user to log events
    while (1) {
        // Prompt the user to enter the type of event (e.g. error, warning, info)
        printf("Type of event: ");
        fgets(buffer, 100, stdin);
        strtok(buffer, "\n");
        char* event_type = (char*) malloc(strlen(buffer) + 1);
        strcpy(event_type, buffer);

        // Prompt the user to enter a message for the event
        printf("Event message: ");
        fgets(buffer, 100, stdin);
        strtok(buffer, "\n");
        char* event_message = (char*) malloc(strlen(buffer) + 1);
        strcpy(event_message, buffer);

        // Get the current timestamp and create a new event
        time_t t = time(NULL);
        struct tm* tm = localtime(&t);
        char* timestamp = asctime(tm);
        SystemEvent* event = (SystemEvent*) malloc(sizeof(SystemEvent));
        event->timestamp = timestamp;
        event->event_type = event_type;
        event->event_message = event_message;

        // Add the event to the log
        log[num_events++] = event;

        // If the log is full, double its size
        if (num_events == max_events) {
            max_events *= 2;
            log = (SystemEvent**) realloc(log, sizeof(SystemEvent*) * max_events);
        }

        // Prompt the user to log another event or print the log and exit
        printf("Log another event? (y/n) ");
        char choice;
        scanf("%c", &choice);
        getchar();
        if (choice == 'n') {
            printLog(log, num_events);
            break;
        }
    }

    // Free all memory allocated for the event log and events
    for (int i = 0; i < num_events; i++) {
        free(log[i]->timestamp);
        free(log[i]->event_type);
        free(log[i]->event_message);
        free(log[i]);
    }
    free(log);

    return 0;
}