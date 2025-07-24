//FormAI DATASET v1.0 Category: Log analysis ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char log[] = "2021-10-01 10:10:22 WARNING Some warning message\n"
                 "2021-10-01 10:11:33 ERROR An error message occurred\n"
                 "2021-10-01 10:13:44 INFO An informational message\n"
                 "2021-10-02 10:10:05 WARNING Another warning message\n"
                 "2021-10-02 10:12:56 ERROR Another error message\n"
                 "2021-10-03 10:14:07 INFO A new informational message\n";

    // Split log by line
    char *line;
    line = strtok(log, "\n");

    while (line != NULL) {
        // Extract date, time, and message from line
        char date[11], time[9], message[100];
        sscanf(line, "%s %s %s", date, time, message);

        // Determine log level
        char *level;
        if (strstr(message, "ERROR") != NULL) {
            level = "ERROR";
        } else if (strstr(message, "WARNING") != NULL) {
            level = "WARNING";
        } else {
            level = "INFO";
        }

        // Output log information
        printf("%s [%s] %s\n", date, level, message);

        // Move to next line
        line = strtok(NULL, "\n");
    }

    return 0;
}