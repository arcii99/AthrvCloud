//FormAI DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // opening the log file
    FILE *fp = fopen("example.log", "r");

    // checking if there was any error opening the file
    if(fp == NULL) {
        printf("Unable to open the log file!\n");
        return 1;
    }

    // variable to read each line from the log file
    char line[256];

    // variables to store information about the log
    int total_lines = 0;
    int error_lines = 0;
    int warning_lines = 0;
    int debug_lines = 0;

    // reading each line from the log file
    while(fgets(line, sizeof(line), fp)) {
        total_lines++;

        // checking if the line contains an error message
        if(strstr(line, "ERROR")) {
            error_lines++;
        }

        // checking if the line contains a warning message
        if(strstr(line, "WARNING")) {
            warning_lines++;
        }

        // checking if the line contains a debug message
        if(strstr(line, "DEBUG")) {
            debug_lines++;
        }
    }

    // closing the log file
    fclose(fp);

    // printing the results of the log analysis
    printf("Total lines in the log file: %d\n", total_lines);
    printf("Total error lines: %d\n", error_lines);
    printf("Total warning lines: %d\n", warning_lines);
    printf("Total debug lines: %d\n", debug_lines);

    return 0;
}