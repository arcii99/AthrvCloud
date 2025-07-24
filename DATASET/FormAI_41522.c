//FormAI DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *log_file = fopen("example.log", "r"); // open log file
    char *line = NULL; // line buffer
    size_t line_size = 0; // current line size
    ssize_t read_size = 0; // read size of current line
    int line_num = 1; // current line number
    int error_count = 0; // number of errors encountered
    int warning_count = 0; // number of warnings encountered

    if (!log_file) {
        printf("Error opening file\n");
        return 1; // exit program with error code
    }

    while ((read_size = getline(&line, &line_size, log_file)) != -1) { // read each line of log file
        if (strstr(line, "ERROR")) { // if error found in line
            error_count++;
            printf("Line %d: %s", line_num, line);
        } else if (strstr(line, "WARNING")) { // if warning found in line
            warning_count++;
            printf("Line %d: %s", line_num, line);
        }

        line_num++;
    }

    printf("Number of errors: %d\n", error_count);
    printf("Number of warnings: %d\n", warning_count);

    fclose(log_file); // close log file
    if (line) free(line); // free line buffer

    return 0; // exit program with success code
}