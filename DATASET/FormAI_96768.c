//FormAI DATASET v1.0 Category: System event logger ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_MSG_LEN 100
#define MAX_LOG_ENTRIES 100

typedef struct {
    time_t timestamp;
    char message[MAX_MSG_LEN];
} LogEntry;

// Declare global variables
LogEntry log_entries[MAX_LOG_ENTRIES];
int num_entries = 0;

// Function prototypes
void log_event(char* message);

int main()
{
    printf("Cryptic System Event Logger\n");

    log_event("System starting up...");

    int running = 1;

    while (running) {
        // Keep running until user enters 'q'
        char input[10];
        printf("Enter 'q' to quit: ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "q\n") == 0) {
            running = 0;
            log_event("System shutting down...");
        } else {
            log_event("Unknown command entered");
        }
    }

    // Print out all the logged events
    printf("\nSystem Event Log:\n");
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s - %s\n", ctime(&log_entries[i].timestamp), log_entries[i].message);
    }

    return 0;
}

void log_event(char* message) {
    // Add a new log entry to log_entries array
    LogEntry new_entry;
    new_entry.timestamp = time(NULL);
    strncpy(new_entry.message, message, MAX_MSG_LEN);

    log_entries[num_entries] = new_entry;
    num_entries++;

    printf("Event logged: %s\n", message);
}