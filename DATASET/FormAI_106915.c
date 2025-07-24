//FormAI DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t now;
    char buffer[30];

    time(&now);
    strftime(buffer, 30, "%m-%d-%Y %T", localtime(&now));

    FILE *logfile;
    logfile = fopen("system_event_log.txt", "a+");
    if (logfile == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Write header to log file
    fprintf(logfile, "System Event Log\nDate-Time: %s\n", buffer);
    fprintf(logfile, "----------------------------------------\n");

    // Write sample events to log file
    fprintf(logfile, "Event 1: User login\n");
    sleep(1);  // simulate delay
    fprintf(logfile, "Event 2: File created\n");
    sleep(2);
    fprintf(logfile, "Event 3: System shutdown\n");

    fclose(logfile);
    printf("System event log successfully created!\n");

    return 0;
}