//FormAI DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_MSG_LEN 100

// Struct for storing event logs
typedef struct {
    char timestamp[20];
    char message[MAX_EVENT_MSG_LEN];
} event;

int main() {
    int num_events = 0;
    event events[MAX_EVENTS];

    // Get current time
    time_t current_time;
    char timestamp[20];
    time(&current_time);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Log initial start event
    strcpy(events[num_events].timestamp, timestamp);
    strcpy(events[num_events].message, "Program started");
    num_events++;

    // Simulation of program events
    int i;
    for (i = 0; i < 10; i++) {
        time(&current_time);
        strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&current_time));
        strcpy(events[num_events].timestamp, timestamp);

        // Random event message
        char message[MAX_EVENT_MSG_LEN] = {0};
        if (i % 2 == 0) {
            sprintf(message, "Event %d occurred", i);
        } else {
            sprintf(message, "Error during event %d", i);
        }
        strcpy(events[num_events].message, message);

        num_events++;
    }

    // Log final end event
    time(&current_time);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    strcpy(events[num_events].timestamp, timestamp);
    strcpy(events[num_events].message, "Program ended");
    num_events++;

    // Print event logs
    printf("Event Logs:\n");
    for (i = 0; i < num_events; i++) {
        printf("[%s] %s\n", events[i].timestamp, events[i].message);
    }

    return 0;
}