//FormAI DATASET v1.0 Category: System event logger ; Style: accurate
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <syslog.h>

void log_event(int type, char *msg) {
    // Log event to system logger
    openlog("MyEventLogger", LOG_PID | LOG_CONS, LOG_USER);
    syslog(type, msg);
    closelog();

    // Write event details to log file
    FILE *fp;
    fp = fopen("event_log.txt", "a");

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[50];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    fprintf(fp, "[%s] %s: %s\n", timestamp, type == LOG_INFO ? "INFO" : 
        (type == LOG_WARNING ? "WARNING" : "ERROR"), msg);

    fclose(fp);
}

int main() {
    // Log events of different types
    log_event(LOG_INFO, "System started");
    log_event(LOG_WARNING, "Disk space low");
    log_event(LOG_ERR, "Connection timed out");

    return 0;
}