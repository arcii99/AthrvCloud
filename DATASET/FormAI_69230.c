//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get current time
void getCurrentTime(char *timeString) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(timeString, "[%d-%02d-%02d %02d:%02d:%02d]", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// function to log events to file
void logEvent(char *event, char *source) {
    char timeString[30];
    getCurrentTime(timeString);
    FILE *fp = fopen("eventlog.txt", "a");
    fprintf(fp, "%s [%s]: %s\n", timeString, source, event);
    fclose(fp);
}

int main() {
    // example usage
    logEvent("Connection established", "Network");
    logEvent("Message received", "Server");
    logEvent("Message delivered", "Client");
    return 0;
}