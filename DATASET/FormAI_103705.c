//FormAI DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/* Define a struct to store log data */
struct log_entry {
    char timestamp[25];
    char level[10];
    char message[MAX_LINE_LENGTH];
};

/* Define function to parse a line of log data */
int parse_log_entry(char* line, struct log_entry* entry) {
    char* token;
    int token_count = 0;

    token = strtok(line, " "); /* split by space */
    while (token != NULL && token_count < 3) {
        if (token_count == 0) {
            strcpy(entry->timestamp, token);
        } else if (token_count == 1) {
            strcpy(entry->level, token);
        } else {
            strcpy(entry->message, token);
        }
        token_count++;
        token = strtok(NULL, " ");
    }

    /* Check if there were enough tokens */
    if (token_count != 3) {
        return -1; /* invalid log entry */
    }

    return 0; /* success */
}

/* Define main function */
int main(int argc, char** argv) {
    FILE* log_file;
    char log_line[MAX_LINE_LENGTH];
    struct log_entry entry;
    int num_warnings = 0;
    int num_errors = 0;

    /* Check command-line arguments */
    if (argc != 2) {
        printf("Usage: %s log_file\n", argv[0]);
        exit(1);
    }

    /* Open log file */
    log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    /* Read log file line by line */
    while (fgets(log_line, MAX_LINE_LENGTH, log_file) != NULL) {
        /* Parse log entry */
        if (parse_log_entry(log_line, &entry) == 0) {
            /* Analyze log entry */
            if (strcmp(entry.level, "WARN") == 0) {
                num_warnings++;
            } else if (strcmp(entry.level, "ERROR") == 0) {
                num_errors++;
            }
        }
    }

    /* Close log file */
    fclose(log_file);

    /* Output analysis result and peace message */
    printf("Log analysis complete. Found %d warnings and %d errors.\n", num_warnings, num_errors);
    printf("Remember, peace is not merely the absence of tension, but the presence of justice and equality. - Martin Luther King Jr.\n");

    return 0;
}