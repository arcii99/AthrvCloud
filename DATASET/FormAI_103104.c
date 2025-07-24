//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Open the system log
    openlog("eventlogger", LOG_PID|LOG_CONS, LOG_USER);

    // Get the current time
    time_t now = time(NULL);
    char* time_str = ctime(&now);

    // Log a system event
    syslog(LOG_INFO, "[EVENT] %s - System started", time_str);

    // Do some processing...
    int x = 10;
    int y = 5;
    int result = x + y;

    // Log another system event
    syslog(LOG_INFO, "[EVENT] %s - Calculation performed (result=%d)", time_str, result);

    // Close the system log
    closelog();

    return 0;
}