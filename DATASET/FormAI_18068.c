//FormAI DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <syslog.h>

#define LOG_NAME "EventLogger"

int main() {
    // Open system logging facility
    openlog(LOG_NAME, LOG_PID | LOG_CONS, LOG_USER);

    // Initialize the random number generator
    srand(time(NULL));

    // Simulate random events and log them
    for(int i = 0; i < 50; i++) {
        int event_id = rand() % 3 + 1; // Generate a random event ID
        switch(event_id) {
            case 1:
                syslog(LOG_INFO, "An informational event occurred.");
                break;
            case 2:
                syslog(LOG_WARNING, "A warning event occurred.");
                break;
            case 3:
                syslog(LOG_ERR, "An error event occurred.");
                break;
        }
        sleep(1); // Wait for 1 second before logging another event
    }

    // Close the system logging facility
    closelog();

    return 0;
}