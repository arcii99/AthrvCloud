//FormAI DATASET v1.0 Category: System event logger ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define event struct
typedef struct Event {
    int id;
    char* type;
    char* timestamp;
    char* message;
} Event;

void log_event(Event event) {
    // open file in append mode
    FILE* file = fopen("event_log.txt", "a");
    if (file == NULL) {
        printf("Error: Unable to open file!\n");
        exit(EXIT_FAILURE);
    }

    // write event details to file
    fprintf(file, "[%s] #%d - %s: %s\n", event.timestamp, event.id, event.type, event.message);

    // close file
    fclose(file);
}

int main() {
    // initialize random number generator
    srand(time(NULL));

    // create an example event
    Event event;
    event.id = rand() % 1000 + 1; // generate random event id
    event.type = "INFO";
    event.timestamp = "2021-04-13 14:35:00";
    event.message = "Event logged successfully";

    // log event
    log_event(event);

    return 0;
}