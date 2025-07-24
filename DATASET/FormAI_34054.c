//FormAI DATASET v1.0 Category: System event logger ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event) {
    FILE *fp;
    char timestamp[50], log[100];

    // Get the current time and date.
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(timestamp, "[%04d-%02d-%02d %02d:%02d:%02d]", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Build the log entry.
    sprintf(log, "%s %s\n", timestamp, event);

    // Open the log file for appending.
    fp = fopen("events.log", "a");

    if (fp != NULL) {
        // Write the log entry to the file.
        fwrite(log, sizeof(log[0]), sizeof(log)/sizeof(log[0]), fp);
        fclose(fp);
    }
}

int main() {
    // Log a sample event.
    logEvent("System startup");

    // ... do some work ...

    // Log another event.
    logEvent("System shutdown");
}