//FormAI DATASET v1.0 Category: System event logger ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define an event struct to hold event information
typedef struct {
    double timestamp;
    char message[100];
} Event;

int main() {
    // Define an array to hold event logs
    Event log[50];
    int log_size = 0;

    // Get current time and format as string
    time_t current_time;
    time(&current_time);
    char time_str[25];
    strftime(time_str, 25, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Log initial event
    Event init_event = {
        .timestamp = difftime(time(NULL), 0),
        .message = "Program initialized"
    };
    log[log_size++] = init_event;

    // Simulate some events
    for (int i = 0; i < 10; i++) {
        // Wait for a random period of time (up to 2 seconds)
        srand(time(NULL));
        double wait_time = (double) rand() / (double) RAND_MAX * 2.0;
        sleep(wait_time);

        // Create event and log it
        Event event = {
            .timestamp = difftime(time(NULL), 0),
            .message = "Event occurred"
        };
        log[log_size++] = event;
    }

    // Log final event
    Event final_event = {
        .timestamp = difftime(time(NULL), 0),
        .message = "Program ended"
    };
    log[log_size++] = final_event;

    // Print log
    printf("Event Log:\n");
    for (int i = 0; i < log_size; i++) {
        printf("[%s] %s\n", time_str, log[i].message);
    }

    return 0;
}