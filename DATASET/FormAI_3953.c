//FormAI DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_LINE_SIZE 256

int main(int argc, char** argv) {
    FILE* log_file;
    char* log_filename = "application.log";
    char* search_term;
    char log_line[MAX_LINE_SIZE] = {'\0'};
    int line_number = 0;
    int matching_lines_count = 0;

    if (argc < 2) {
        printf("Usage: %s <search-term>\n", argv[0]);
        return 1;
    }
    search_term = argv[1];

    log_file = fopen(log_filename, "r");
    if (log_file == NULL) {
        printf("Error: Unable to open log file '%s'.\n", log_filename);
        return 1;
    }

    printf("Showing log lines that contain the search term '%s':", search_term);

    while (fgets(log_line, MAX_LINE_SIZE, log_file) != NULL) {
        line_number++;

        if (strstr(log_line, search_term) != NULL) {
            matching_lines_count++;
            printf("%d: %s", line_number, log_line);
        }
    }

    printf("Search completed. Found %d lines that contain the search term.\n", matching_lines_count);

    fclose(log_file);

    return 0;
}