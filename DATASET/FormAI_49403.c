//FormAI DATASET v1.0 Category: System event logger ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Define a struct to hold event information
struct Event {
    char name[50];
    char time[50];
    char date[50];
};

// Define a function to log events in a file
void logEvent(struct Event* event) {
    // Open the event file in append mode
    FILE* fp = fopen("event.log", "a");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error: Could not open event file\n");
        return;
    }

    // Get the current time and date
    time_t t;
    time(&t);
    struct tm* tm_info = localtime(&t);
    strftime(event->time, 50, "%H:%M:%S", tm_info);
    strftime(event->date, 50, "%Y-%m-%d", tm_info);

    // Write the event details to the file
    fprintf(fp, "%s\t%s\t%s\n", event->date, event->time, event->name);

    // Close the file
    fclose(fp);
}

int main() {
    printf("Welcome to the Mind-Bending Event Logger!\n");

    // Prompt the user to enter event information
    struct Event event;
    printf("Please enter the name of the event: ");
    fgets(event.name, 50, stdin);

    // Remove newline character from event name
    int i = 0;
    while (event.name[i] != '\n') {
        i++;
    }
    event.name[i] = '\0';

    // Log the event in the file
    logEvent(&event);

    // Print a confirmation message
    printf("Event logged successfully!\n");

    return 0;
}