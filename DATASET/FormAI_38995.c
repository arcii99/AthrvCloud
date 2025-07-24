//FormAI DATASET v1.0 Category: System event logger ; Style: enthusiastic
#include <stdio.h>
#include <time.h>

// Event struct
typedef struct Event {
    time_t timestamp;
    char* message;
} Event;

// Log function to print events to console
void logEvent(Event event) {
    printf("[%s]: %s\n", ctime(&event.timestamp), event.message);
}

// main function
int main() {
    // array of events
    Event events[5];
    // get current time
    time_t currentTime = time(NULL);

    // create events and add to array
    events[0].timestamp = currentTime;
    events[0].message = "Application started";

    events[1].timestamp = currentTime + 5;
    events[1].message = "Opened file1.txt";

    events[2].timestamp = currentTime + 10;
    events[2].message = "Saved changes to file1.txt";

    events[3].timestamp = currentTime + 15;
    events[3].message = "Opened file2.txt";

    events[4].timestamp = currentTime + 20;
    events[4].message = "Application closed";

    // log all events
    for (int i = 0; i < 5; i++) {
        logEvent(events[i]);
    }

    return 0;
}