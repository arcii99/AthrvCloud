//FormAI DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *logfile;

    char line[100];
    char *filename = "server.log";

    logfile = fopen(filename, "r");

    if (logfile == NULL) {
        printf("Could not open log file %s\n", filename);
        exit(1);
    }

    int error_count = 0;
    int warning_count = 0;

    while (fgets(line, sizeof(line), logfile)) {

        if (strstr(line, "[ERROR]")) {
            error_count++;
        }

        if (strstr(line, "[WARNING]")) {
            warning_count++;
        }        
    }

    fclose(logfile);

    printf("\nNumber of Errors: %d\n", error_count);
    printf("Number of Warnings: %d\n", warning_count);

    return 0;
}