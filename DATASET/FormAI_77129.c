//FormAI DATASET v1.0 Category: System event logger ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_LOG "event.log"

int main() {

    // Open the event log file to append events
    FILE *event_log_file = fopen(EVENT_LOG, "a");

    // Get current time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char datetime[20];
    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", t);

    // Logging system boot event
    fprintf(event_log_file, "[%s] Boot event detected.\n", datetime);

    // Simulate system events
    int i;
    for (i = 0; i < 10; i++) {
        // Sleep for random amount of time between 1-5 seconds
        int sleep_time = (rand() % 5) + 1;
        sleep(sleep_time);

        // Log the event
        now = time(NULL);
        t = localtime(&now);
        strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", t);
        fprintf(event_log_file, "[%s] System event #%d occurred after %d seconds of previous event.\n", datetime, i+1, sleep_time);
    }

    // Logging system shutdown event
    now = time(NULL);
    t = localtime(&now);
    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", t);
    fprintf(event_log_file, "[%s] System shutdown event detected.\n", datetime);

    // Close the event log file
    fclose(event_log_file);

    return 0;
}