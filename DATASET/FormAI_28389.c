//FormAI DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 500

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Please provide a log file path to be analysed.\n");
        return 1;
    }

    char* file_path = argv[1];
    FILE* log_file = fopen(file_path, "r");

    if(log_file == NULL) {
        printf("Cannot open file %s\n", file_path);
        return 1;
    }

    char line[MAX_LINE_SIZE];
    int total_lines = 0, error_lines = 0, warning_lines = 0;
    int most_common_error_code = 0;
    char most_common_error_code_string[10];

    int error_code_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (fgets(line, MAX_LINE_SIZE, log_file)) {
        total_lines++;

        if (strstr(line, "ERROR")) {
            error_lines++;

            char* error_code_ptr = strstr(line, "ERROR CODE:");
            if (error_code_ptr) {
                char error_code_string[10];
                sscanf(error_code_ptr, "ERROR CODE: %s", error_code_string);

                int error_code = atoi(error_code_string);
                error_code_count[error_code]++;
                if (error_code_count[error_code] > error_code_count[most_common_error_code]) {
                    most_common_error_code = error_code;
                    strcpy(most_common_error_code_string, error_code_string);
                }
            }
        }
        else if (strstr(line, "WARNING")) {
            warning_lines++;
        }
    }

    printf("\nLog analysis results:\n");
    printf("Total lines: %d\n", total_lines);
    printf("Total error lines: %d\n", error_lines);
    printf("Total warning lines: %d\n", warning_lines);

    if (most_common_error_code) {
        printf("Most common error code: %s (appeared %d times)\n", most_common_error_code_string, error_code_count[most_common_error_code]);
    }

    fclose(log_file);

    return 0;
}