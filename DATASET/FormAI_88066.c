//FormAI DATASET v1.0 Category: System event logger ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the event log
#define MAX_LOG_SIZE 1000

// Define the maximum size of the event description
#define MAX_EVENT_DESC_SIZE 50

// Define the structure of the event log
struct EventLog {
    char timestamp[25];
    char event_desc[MAX_EVENT_DESC_SIZE];
};

// Define the function to generate random event descriptions
void generate_event_desc(char *event_desc) {
    const char *event_types[] = {"Login", "Logout", "Error", "Warning", "Success"};
    const char *event_objects[] = {"System", "Database", "Network", "File", "User"};
    const char *event_actions[] = {"Accessed", "Modified", "Deleted", "Created", "Updated"};
    const int num_event_types = 5;
    const int num_event_objects = 5;
    const int num_event_actions = 5;
    // Seed the random number generator
    srand(time(NULL));
    // Choose a random event type, object, and action
    int event_type_index = rand() % num_event_types;
    int event_object_index = rand() % num_event_objects;
    int event_action_index = rand() % num_event_actions;
    // Format the event description string
    sprintf(event_desc, "%s %s %s", event_types[event_type_index], event_objects[event_object_index], event_actions[event_action_index]);
}

int main() {
    // Create an array to hold the event log
    struct EventLog event_log[MAX_LOG_SIZE];
    // Set the current time as the first timestamp in the log
    time_t current_time = time(NULL);
    sprintf(event_log[0].timestamp, "%s", ctime(&current_time));
    // Generate random event descriptions and timestamps for the remaining log entries
    for (int i = 1; i < MAX_LOG_SIZE; i++) {
        // Set the current time as the timestamp for this log entry
        current_time = time(NULL);
        sprintf(event_log[i].timestamp, "%s", ctime(&current_time));
        // Generate a random event description for this log entry
        char event_desc[MAX_EVENT_DESC_SIZE];
        generate_event_desc(event_desc);
        sprintf(event_log[i].event_desc, "%s", event_desc);
    }
    // Print the event log to the console
    printf("Event Log:\n");
    for (int i = 0; i < MAX_LOG_SIZE; i++) {
        printf("%s: %s\n", event_log[i].timestamp, event_log[i].event_desc);
    }
    return 0;
}