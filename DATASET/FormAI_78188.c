//FormAI DATASET v1.0 Category: System event logger ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

/* Define structure for event log */
typedef struct EventLog {
    char timestamp[25];
    char source[50];
    char event[100];
} EventLog;

/* Function to get current timestamp */
char* getCurrentTimestamp() {
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    time_t now = current_time.tv_sec;
    struct tm tstruct;
    char *timestamp = (char*) malloc(25);
    tstruct = *localtime(&now);
    strftime(timestamp, 25, "%Y-%m-%d %H:%M:%S", &tstruct);
    return timestamp;
}

/* Function to log system events */
void logEvent(char source[], char event[]) {
    FILE *fp;
    char *timestamp = getCurrentTimestamp();
    EventLog log;
    strcpy(log.timestamp, timestamp);
    strcpy(log.source, source);
    strcpy(log.event, event);
    fp = fopen("system_event.log", "a");
    fprintf(fp, "%s : %s : %s\n", log.timestamp, log.source, log.event);
    fclose(fp);
}

/* Sample usage */
int main() {
    logEvent("Application", "User authentication successful");
    logEvent("Database", "Connection established");
    return 0;
}