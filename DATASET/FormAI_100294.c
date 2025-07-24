//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_IP_LENGTH 16

struct IntrusionEvent {
    char timestamp[MAX_LINE_LENGTH];
    char ip_address[MAX_IP_LENGTH];
    char description[MAX_LINE_LENGTH];
};

void parse_line(char* line, struct IntrusionEvent* event) {
    char* token;
    int i = 0;

    token = strtok(line, ",");
    while (token != NULL) {
        switch (i) {
            case 0:
                strcpy(event->timestamp, token);
                break;
            case 1:
                strcpy(event->ip_address, token);
                break;
            case 2:
                strcpy(event->description, token);
                break;
        }
        token = strtok(NULL, ",");
        i++;
    }
}

int main(int argc, char** argv) {
    // array for storing the last 10 intrusion events
    struct IntrusionEvent intrusion_events[10];
    int num_intrusion_events = 0;

    // read the intrusion log file
    FILE* log_file = fopen("intrusion.log", "r");
    if (log_file == NULL) {
        printf("Error: could not open intrusion log file\n");
        return -1;
    }

    // scan the log file for intrusion events
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        // parse the line into an IntrusionEvent struct
        struct IntrusionEvent event;
        parse_line(line, &event);

        // add the event to the array
        if (num_intrusion_events < 10) {
            intrusion_events[num_intrusion_events] = event;
            num_intrusion_events++;
        } else {
            // shift the array to make room for the new event
            for (int i = 0; i < 9; i++) {
                intrusion_events[i] = intrusion_events[i+1];
            }
            intrusion_events[9] = event;
        }

        // check for repeated events from the same IP
        int num_repeated_events = 0;
        for (int i = 0; i < num_intrusion_events-1; i++) {
            if (strcmp(event.ip_address, intrusion_events[i].ip_address) == 0) {
                num_repeated_events++;
            }
        }

        // if there are more than 5 repeated events, trigger an alert
        if (num_repeated_events >= 5) {
            printf("ALERT: %d repeated intrusion events from %s\n", num_repeated_events, event.ip_address);
            printf("Description: %s\n", event.description);
        }
    }

    fclose(log_file);

    return 0;
}