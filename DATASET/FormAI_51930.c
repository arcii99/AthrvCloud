//FormAI DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>
#include <syslog.h>

int main()
{
    openlog("event_logger", LOG_PID | LOG_CONS, LOG_USER);

    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    syslog(LOG_INFO, "Event occurred at %s", c_time_string);
    printf("Event logged successfully.");

    closelog();

    return 0;
}