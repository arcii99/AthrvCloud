//FormAI DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_LOG_LINES 10000 // maximum number of log lines to read
#define MAX_LOG_LINE_SIZE 100 // maximum size of each log line

int main() {

    // array to hold the log lines
    char log_lines[MAX_LOG_LINES][MAX_LOG_LINE_SIZE];

    // array to hold the error codes and their occurrence count
    int error_count[100] = {0};

    // read the log file
    FILE *log_file = fopen("sample_log_file.log", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    char line[MAX_LOG_LINE_SIZE];
    int line_count = 0;
    while (fgets(line, MAX_LOG_LINE_SIZE, log_file) != NULL && line_count < MAX_LOG_LINES) {
        strcpy(log_lines[line_count], line); // store the line in array
        line_count++;
    }
    fclose(log_file);

    // analyze the log lines
    int i, j, k, error_code;
    for (i = 0; i < line_count; i++) {
        j = 0;
        while (log_lines[i][j] != ' ') j++; // find the end of the date/time part
        j++; // skip the space after the date/time
        k = j;
        while (log_lines[i][k] != ' ') k++; // find the end of the process name
        k++; // skip the space after the process name
        if (log_lines[i][k] == 'E') { // check if it's an error line
            k += 2; // skip the "E/" part
            error_code = (log_lines[i][k] - '0') * 10 + (log_lines[i][k+1] - '0'); // extract the error code
            error_count[error_code]++; // increment the occurrence count
        }
    }

    // print the error codes and their occurrence count
    printf("Error Code\tOccurrence Count\n");
    for (i = 0; i < 100; i++) {
        if (error_count[i] > 0) {
            printf("%d\t\t%d\n", i, error_count[i]);
        }
    }

    return 0;
}