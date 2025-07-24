//FormAI DATASET v1.0 Category: System event logger ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// defining the log event structure
typedef struct {
    time_t timestamp;
    char event[100];
} LogEvent;

// function definitions
void logEvent(char *eventMessage);
void displayEvents();

// defining the log array
LogEvent logArray[50];

// counter for number of events logged
int index = 0;

int main() {
    // display instructions to user
    printf("Welcome to the System Event Logger!\n");
    printf("Please enter the event you want to log. When you're done, enter 'quit' to exit the program.\n");

    char input[100];

    // loop to continuously accept event log messages from user until they enter "quit"
    while(1) {
        // accept input from user
        printf("> ");
        fgets(input, 100, stdin);

        // remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // check if user entered "quit" to exit program
        if(strcmp(input, "quit") == 0) {
            printf("Thank you for using the System Event Logger!");
            break;
        }
        else {
            // log event
            logEvent(input);
        }
    }

    // display all events logged by user
    displayEvents();

    return 0;
}

void logEvent(char *eventMessage) {
    // create new log event object
    LogEvent event;

    // set timestamp to current time
    event.timestamp = time(NULL);

    // copy user input event message into event object
    strcpy(event.event, eventMessage);

    // add event object to log array
    logArray[index] = event;
    index++;
}

void displayEvents() {
    printf("\n\nAll events logged:\n");

    // loop through log array to display all log events
    for(int i = 0; i < index; i++) {
        // convert timestamp to readable format
        char* timestamp = ctime(&logArray[i].timestamp);
        timestamp[strlen(timestamp) - 1] = 0;

        // display log event message with timestamp
        printf("Timestamp: %s\tEvent: %s\n", timestamp, logArray[i].event);
    }
}