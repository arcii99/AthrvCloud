//FormAI DATASET v1.0 Category: Log analysis ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024 // maximum buffer size
#define MAX_LOG_FILES 50 // maximum number of log files allowed

// This function will parse the log file and return the summary
int parse_log_file(char* file_name, int* total_lines, int* error_lines)
{
    int line_count = 0;
    int error_count = 0;

    // open the log file
    FILE* fp = fopen(file_name, "r");

    if(fp == NULL) {
        printf("Error opening log file: %s\n", file_name);
        return -1;
    }

    // read through each line of the log file
    char buffer[MAX_BUF_SIZE];
    while(fgets(buffer, MAX_BUF_SIZE, fp)) {
        line_count++;

        // check if this is an error line
        if(strstr(buffer, "ERROR") != NULL) {
            error_count++;
        }
    }

    // close the file
    fclose(fp);

    // save the summary
    *total_lines = line_count;
    *error_lines = error_count;

    return 0;
}

int main(int argc, char* argv[])
{
    int i = 0;
    int total_lines = 0;
    int error_lines = 0;

    if(argc < 2) {
        printf("Usage: log_analyzer [<file_name_1>] [<file_name_2>] ... [<file_name_n>]\n");
        return -1;
    }

    // process each log file and generate a summary
    for(i = 1; i < argc; i++) {
        if(parse_log_file(argv[i], &total_lines, &error_lines) == -1) {
            continue;
        }

        // print the summary
        printf("Log file '%s' processed.\n", argv[i]);
        printf("Total lines: %d\n", total_lines);
        printf("Error lines: %d\n", error_lines);
        printf("\n");
    }

    return 0;
}