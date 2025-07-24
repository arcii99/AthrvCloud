//FormAI DATASET v1.0 Category: System event logger ; Style: funny
/*
 * The following program is a unique C system event logger.
 * It logs all events in a funny and creative way.
 * Minimum 50 lines of pure joy and excitement, guaranteed!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *event, char *location) {
    time_t now = time(NULL);
    printf("EVENT: %s\n", event);
    printf("LOCATION: %s\n", location);
    printf("TIME: %s\n", ctime(&now));
    printf("------------------------------------------------\n");
}

int main() {
    char locations[5][20] = {
        "Living Room",
        "Kitchen",
        "Bedroom",
        "Bathroom",
        "Garage"
    };

    char events[5][50] = {
        "A tree just fell on the house!",
        "The dishwasher just exploded!",
        "I just won the lottery!",
        "Aliens have landed in the backyard!",
        "The cat just learned how to talk!"
    };

    srand(time(NULL));

    printf("Welcome to the funny event logger!\n");
    printf("Press CTRL+C to exit at any time...\n");

    while(1) {
        int location_index = rand() % 5;
        int event_index = rand() % 5;

        log_event(events[event_index], locations[location_index]);

        printf("Waiting for the next hilarious event...\n");
        printf("------------------------------------------------\n");

        sleep(1);
    }

    return 0;
}