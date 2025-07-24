//FormAI DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>
#include <stdlib.h>

/* A funny system event logger example program */

int main() {
    printf("Welcome to the most hilarious event logger you'll ever see!\n");
    printf("We're going to make sure that every event is recorded, but with a twist.\n");

    int num_events = 0;
    printf("How many events do you want to log? Enter a number: ");
    scanf("%d", &num_events);

    printf("\n*** Let's get started! ***\n\n");

    FILE *fp = fopen("event_log.txt", "w");
    if (fp == NULL) {
        printf("Uh oh, something went wrong. Could not open file.\n");
        exit(1);
    }

    for (int i = 1; i <= num_events; i++) {
        printf("Event #%d: ", i);
        char event[100];
        scanf("%s", event);
        fprintf(fp, "Event #%d: %s (just kidding, nothing happened LOL)\n", i, event);
    }

    fclose(fp);

    printf("\nWe're all done! Check out your event log in the file 'event_log.txt'.\n");
    printf("But remember, nothing interesting happened. Have a good day!\n");

    return 0;
}