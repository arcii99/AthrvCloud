//FormAI DATASET v1.0 Category: System event logger ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

/* This program logs system events with varying levels of severity */

int main(void) {

    openlog("event_logger", LOG_PID|LOG_CONS, LOG_USER);

    syslog(LOG_EMERG, "E: System is unusable.");
    syslog(LOG_ALERT, "A: Action must be taken immediately.");
    syslog(LOG_CRIT, "C: Critical conditions.");
    syslog(LOG_ERR, "E: Error conditions.");
    syslog(LOG_WARNING, "W: Warning conditions.");
    syslog(LOG_NOTICE, "N: Normal but significant condition.");
    syslog(LOG_INFO, "I: Informational messages.");
    syslog(LOG_DEBUG, "D: Debug-level messages.");

    closelog();

    return EXIT_SUCCESS;
}