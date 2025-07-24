//FormAI DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LINE_LENGTH 200

void print_usage()
{
    printf("Usage: log_analyzer <log_file_path>\n");
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        print_usage();
        return -1;
    }

    printf("Starting log analysis...\n");

    FILE *log_file = fopen(argv[1], "r");

    if (log_file == NULL) {
        printf("Failed to open log file.\n");
        return -1;
    }

    char log_lines[MAX_LOG_LINES][MAX_LOG_LINE_LENGTH];
    char *tokens[MAX_LOG_LINES][10];
    int num_lines = 0;
    int i, j;

    // read log file line by line
    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, MAX_LOG_LINE_LENGTH, log_file) != NULL) {
        strcpy(log_lines[num_lines], line);

        // tokenize the log line
        char *token = strtok(line, " ");
        j = 0;
        while (token != NULL) {
            tokens[num_lines][j] = token;
            token = strtok(NULL, " ");
            j++;
        }

        num_lines++;
    }

    fclose(log_file);

    // analyze log data
    int num_success = 0;
    int num_error = 0;
    char *error_messages[MAX_LOG_LINES];
    int num_unique_errors = 0;

    for (i = 0; i < num_lines; i++) {
        if (strcmp(tokens[i][6], "200") == 0) {
            num_success++;
        } else {
            num_error++;
            int exists = 0;
            for (j = 0; j < num_unique_errors; j++) {
                if (strcmp(error_messages[j], tokens[i][8]) == 0) {
                    exists = 1;
                    break;
                }
            }

            if (!exists) {
                char *message = malloc(strlen(tokens[i][8]) + 1);
                strcpy(message, tokens[i][8]);
                error_messages[num_unique_errors] = message;
                num_unique_errors++;
            }
        }
    }

    printf("=========================\n");
    printf("Log analysis complete!\n");
    printf("=========================\n");
    printf("Number of successful requests: %d\n", num_success);
    printf("Number of failed requests: %d\n", num_error);
    printf("List of unique error messages:\n");
    for (i = 0; i < num_unique_errors; i++) {
        printf("- %s\n", error_messages[i]);
        free(error_messages[i]);
    }
    printf("=========================\n");

    return 0;
}