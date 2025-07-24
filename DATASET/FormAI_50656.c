//FormAI DATASET v1.0 Category: System event logger ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 10000

typedef struct {
    time_t timestamp;
    char event_desc[100];
} LogEvent;

int main() {
    LogEvent event_log[MAX_EVENTS];
    int num_events = 0;

    time_t current_time;
    char input[100];
    printf("Enter a description of the event (max 100 characters), or 'exit' to quit:\n");

    while (fgets(input, 100, stdin) != NULL) {
        if (input[0] != '\n') {
            if (strcmp(input, "exit\n") == 0) {
                break;
            } else {
                current_time = time(NULL);
                event_log[num_events].timestamp = current_time;
                strncpy(event_log[num_events].event_desc, input, 99);
                num_events++;
            }
        }
        printf("Enter a description of the event (max 100 characters), or 'exit' to quit:\n");
    }

    printf("\nEvent Log:\n");

    for (int i = 0; i < num_events; i++) {
        printf("%s - %s", ctime(&event_log[i].timestamp), event_log[i].event_desc);
    }

    return 0;
}