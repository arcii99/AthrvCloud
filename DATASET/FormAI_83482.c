//FormAI DATASET v1.0 Category: System event logger ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_EVENTS 1000
#define MAX_LENGTH 100

//Structure to store event information
struct event {
    int id;
    char name[MAX_LENGTH];
    char type[MAX_LENGTH];
    char timestamp[MAX_LENGTH];
};

//Function to write an event to the log file
void write_event(struct event e) {
    FILE *fptr;

    // Open the log file in append mode
    fptr = fopen("event_log.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Prepare the event string to be written to the log file
    char event_str[MAX_LENGTH*4];
    snprintf(event_str, MAX_LENGTH*4, "%d,%s,%s,%s\n", e.id, e.name, e.type, e.timestamp);

    // Write the event string to the log file
    fputs(event_str, fptr);

    // Close the log file
    fclose(fptr);
}

int main()
{
    //Create an array to store events
    struct event events[MAX_EVENTS];

    int num_events = 0; //Number of events stored in the array
    int event_id = 1; //ID of the next event to be added

    while (1) {
        //Ask the user to enter the name of the event
        char name[MAX_LENGTH];
        printf("Enter the name of the event (or 'quit' to end): ");
        fgets(name, MAX_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0; //Remove the trailing newline character

        if (strcmp(name, "quit") == 0) {
            //End the program if the user enters 'quit'
            break;
        }

        //Ask the user to enter the type of the event
        char type[MAX_LENGTH];
        printf("Enter the type of the event: ");
        fgets(type, MAX_LENGTH, stdin);
        type[strcspn(type, "\n")] = 0;

        //Get the current timestamp
        time_t now;
        time(&now);
        char timestamp[MAX_LENGTH];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

        //Create a new event with the entered information and add it to the array
        struct event e = {event_id, name, type, timestamp};
        events[num_events] = e;
        num_events++;
        event_id++;

        //Write the event to the log file
        write_event(e);

        printf("Event recorded.\n");
    }

    //Print out all the events that were recorded
    printf("Events recorded:\n");
    printf("ID\tName\t\tType\tTimestamp\n");
    for (int i = 0; i < num_events; i++) {
        printf("%d\t%s\t%s\t%s\n", events[i].id, events[i].name, events[i].type, events[i].timestamp);
    }

    return 0;
}