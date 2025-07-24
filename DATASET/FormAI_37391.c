//FormAI DATASET v1.0 Category: System event logger ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* C System event logger program */
/* This program logs events with a timestamp and random values */

void log_event(char* event_name, int random_value)
{
    /* get current time */
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    /* format time as string for logging */
    char timestamp[20];
    sprintf(timestamp, "%04d-%02d-%02d %02d:%02d:%02d",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    /* log event with timestamp and random value */
    printf("[%s] %s - value: %d\n", timestamp, event_name, random_value);
}

int main()
{
    srand(time(NULL)); /* seed random number generator */
    int i;

    /* log 50 random events */
    for (i = 0; i < 50; i++) {
        int random_value = rand() % 100; /* generate random value between 0 and 99 */
        if (random_value < 50) {
            log_event("event A", random_value);
        } else {
            log_event("event B", random_value);
        }
    }

    return 0;
}