//FormAI DATASET v1.0 Category: Log analysis ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *log_file_path = "/var/log/messages";
const char *error_string = "error";
const char *warning_string = "warning";
const char *info_string = "info";
const int max_line_length = 1024;

void parse_line(const char *line) {
    if (strstr(line, error_string)) {
        printf("Error: %s", line);
    } else if (strstr(line, warning_string)) {
        printf("Warning: %s", line);
    } else if (strstr(line, info_string)) {
        printf("Information: %s", line);
    }
}

int main() {
    FILE *log_file = fopen(log_file_path, "r");
    if (log_file == NULL) {
        printf("Error opening log file!");
        exit(1);
    }

    char *line_buffer = malloc(max_line_length);
    if (line_buffer == NULL) {
        printf("Error allocating memory!");
        exit(1);
    }

    while (fgets(line_buffer, max_line_length, log_file)) {
        parse_line(line_buffer);
    }

    free(line_buffer);
    fclose(log_file);

    printf("Log analysis complete! Wow, that was exciting! :)\n");

    return 0;
}