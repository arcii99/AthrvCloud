//FormAI DATASET v1.0 Category: Log analysis ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000

struct Log {
    char* message;
    int severity;
    long timestamp;
};

typedef struct Log Log;

void parse_log_file(char* file_path, Log* log_array) {
    FILE* log_file = fopen(file_path, "r");

    if (log_file == NULL) {
        printf("Error: log file could not be opened.");
        exit(1);
    }

    char current_line[1024];
    int log_index = 0;

    while (fgets(current_line, 1024, log_file) != NULL && log_index < MAX_LOG_SIZE) {
        Log current_log;

        char* token = strtok(current_line, " ");
        int token_index = 0;

        while (token != NULL) {
            switch (token_index) {
                case 0:
                    current_log.timestamp = atol(token);
                    break;
                case 1:
                    current_log.severity = atoi(token);
                    break;
                default:
                    strcat(current_log.message, token);
                    strcat(current_log.message, " ");
                    break;
            }

            token = strtok(NULL, " ");
            token_index++;
        }

        log_array[log_index] = current_log;
        log_index++;
    }

    fclose(log_file);
}

void print_logs(Log* log_array, int array_size, int minimum_severity) {
    for (int i = 0; i < array_size; i++) {
        if (log_array[i].severity >= minimum_severity) {
            printf("[%ld] [Severity %d] %s\n", log_array[i].timestamp, log_array[i].severity, log_array[i].message);
        }
    }
}

int main() {
    Log logs[MAX_LOG_SIZE];

    parse_log_file("example_logs.log", logs);

    print_logs(logs, MAX_LOG_SIZE, 3);

    return 0;
}