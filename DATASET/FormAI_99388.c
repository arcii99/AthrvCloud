//FormAI DATASET v1.0 Category: System event logger ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <time.h>

void log_event(char *msg) {
    time_t current_time;
    char *c_time_string;
    int priority = LOG_INFO;

    openlog("My Event Logger", LOG_PID|LOG_CONS, LOG_USER);
    syslog(priority, "%s", msg);

    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    printf("Event logged at: %s", c_time_string);

    closelog();
}

int main(void) {
    char msg[50];
    printf("Enter the event to log: ");
    scanf("%s", msg);

    log_event(msg);
    
    return 0;
}