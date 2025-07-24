//FormAI DATASET v1.0 Category: System event logger ; Style: genious
/*
 * Prodigy System Event Logger
 * An advanced system logger that records events and their details 
 * in a file for future reference.
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_EVENT_SIZE 1000
#define LOG_FILE "events.log"

void log_event(const char* event) {
    FILE* file_pointer = fopen(LOG_FILE, "a");
    if (file_pointer != NULL) {
        // Get current time
        time_t now = time(NULL);
        
        // Write event to file with timestamp
        fprintf(file_pointer, "[%s]: %s\n", ctime(&now), event);

        // Close file
        fclose(file_pointer);
    }
}

int main() {
    char event[MAX_EVENT_SIZE];
    int count = 0;

    printf("Welcome to Prodigy System Event Logger!\n");
    printf("Enter 'exit' to exit the program.\n");

    while(1) {
        // Get event from user
        printf("\nEnter event: ");
        fgets(event, MAX_EVENT_SIZE, stdin);

        // Remove newline character
        event[strcspn(event, "\n")] = 0;

        // Exit condition
        if (strcmp(event, "exit") == 0) {
            break;
        }

        // Log event
        log_event(event);
        count++;

        // Print confirmation message
        printf("\nEvent logged: %s\n", event);
    }

    // Done logging events
    printf("\n%d events logged. Goodbye!\n", count);
    return 0;
}