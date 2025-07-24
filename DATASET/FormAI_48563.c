//FormAI DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the structure for the event
struct Event {
    time_t timestamp;
    char source[50];
    char description[100];
};

// Define the global variables for the event logger
struct Event events[100];
int eventCount = 0;

// Function to add a new event to the logger
void addEvent(char *source, char *description) {
    struct Event newEvent;
    newEvent.timestamp = time(NULL);
    strcpy(newEvent.source, source);
    strcpy(newEvent.description, description);

    events[eventCount] = newEvent;
    eventCount++;
}

// Function to print all events in the logger
void printEvents() {
    printf("\nSystem Event Logger\n");
    printf("--------------------\n");
    for (int i = 0; i < eventCount; i++) {
        printf("%s [%s]: %s\n", ctime(&events[i].timestamp), events[i].source, events[i].description);
    }
}

// Main function to test the event logger
int main() {
    addEvent("System", "Program started");
    addEvent("System", "Files loaded");
    addEvent("User Interface", "Button clicked");
    addEvent("Database", "Data updated");

    printEvents();

    return 0;
}