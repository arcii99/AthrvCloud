//FormAI DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define a structure to hold the event data */
typedef struct Event {
    char name[50];
    char description[200];
    time_t time;
} Event;

/* Define a function to write the event data to the log */
void write_event_to_log(Event event) {
    /* Get the current time */
    time_t current_time = time(NULL);

    /* Open the log file for appending */
    FILE *log_file = fopen("events.log", "a");

    /* Print the event data to the log file */
    fprintf(log_file, "EVENT NAME: %s\n", event.name);
    fprintf(log_file, "TIME: %s", asctime(localtime(&event.time)));
    fprintf(log_file, "DESCRIPTION: %s\n\n", event.description);

    /* Close the log file */
    fclose(log_file);

    /* Print a confirmation message to the console */
    printf("\nEvent logged successfully!\n\n");
}

int main() {
    /* Initialize the event data structure */
    Event event;

    /* Prompt the user for the event information */
    printf("\nWelcome to the event logger program!\n\n");
    printf("Please enter the name of the event: ");
    fgets(event.name, 50, stdin);
    printf("Please enter a brief description of the event: ");
    fgets(event.description, 200, stdin);

    /* Remove the newline character from the string */
    event.name[strcspn(event.name, "\n")] = 0;
    event.description[strcspn(event.description, "\n")] = 0;

    /* Set the event time to the current time */
    event.time = time(NULL);

    /* Write the event data to the log */
    write_event_to_log(event);

    return 0;
}