//FormAI DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <syslog.h>

int main() {
    // Set up the syslog
    setlogmask(LOG_UPTO(LOG_INFO));
    openlog("Event Logger", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    // Generate a random event code
    srand(time(NULL));
    int event_code = rand() % 1000 + 1;

    // Log the event
    syslog(LOG_NOTICE, "Event %d occurred", event_code);

    // Close the syslog
    closelog();

    return 0;
}