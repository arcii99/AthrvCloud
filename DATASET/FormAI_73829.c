//FormAI DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <syslog.h>

#define EVENT_DIR "/var/log/myevents.log"

int main() {
    openlog("mylogger", LOG_PID, LOG_USER);

    time_t current_time;
    char* time_string;
    int event_code;

    printf("Enter the event code: ");
    scanf("%d", &event_code);

    time(&current_time);
    time_string = ctime(&current_time);
    char* log_entry = (char*) malloc(sizeof(char)*(strlen(time_string) + 20));

    sprintf(log_entry, "%s - Event occurred with code %d", time_string, event_code);

    FILE *f = fopen(EVENT_DIR, "a");
    if (f == NULL) {
        syslog(LOG_INFO, "Error: unable to open log file");
    }

    fputs(log_entry, f);
    fclose(f);

    syslog(LOG_INFO, log_entry);

    free(log_entry);

    closelog();

    return 0;
}