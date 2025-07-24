//FormAI DATASET v1.0 Category: System event logger ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int log_event(int event_num) {
    time_t current_time;
    char* event_string;
    int event_status = 0;
    time(&current_time);

    switch(event_num) {
        case 1:
            event_string = "System Booted";
            event_status = 1;
            break;
        case 2:
            event_string = "User Logged In";
            event_status = 1;
            break;
        case 3:
            event_string = "System Shutting Down";
            event_status = 1;
            break;
        default:
            event_string = "Unknown Event";
            event_status = 0;
            break;
    }
    
    printf("%s at %s", event_string, ctime(&current_time));
    return event_status;
}

void recursive_log(int current_event, int total_events) {
    int event_success;
    if(current_event > total_events) {
        return;
    }
    event_success = log_event(current_event);
    if(event_success) {
        recursive_log(current_event + 1, total_events);
    } else {
        printf("Unable to log event %d, exiting...\n", current_event);
        exit(1);
    }
}

int main() {
    int total_events = 5;

    printf("Beginning recursive logging of system events...\n");
    recursive_log(1, total_events);
    printf("All system events successfully logged.\n");

    return 0;
}