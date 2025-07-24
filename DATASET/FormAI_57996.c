//FormAI DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Please provide a log file as argument.\n");
        return EXIT_FAILURE;
    }

    const char *log_file = argv[1];

    FILE *file = fopen(log_file, "r");

    if (file == NULL) {
        fprintf(stderr, "Log file %s does not exist.\n", log_file);
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int num_success = 0;
    int num_error = 0;
    int num_warning = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        // Parse the log line
        char *type_str = strtok(line, ":");
        char *message = strtok(NULL, "\n");

        if (type_str == NULL || message == NULL) {
            continue;
        }

        if (strcmp(type_str, "SUCCESS") == 0) {
            num_success++;
        } else if (strcmp(type_str, "ERROR") == 0) {
            num_error++;
        } else if (strcmp(type_str, "WARNING") == 0) {
            num_warning++;
        }
    }

    printf("Number of SUCCESS logs: %d\n", num_success);
    printf("Number of ERROR logs: %d\n", num_error);
    printf("Number of WARNING logs: %d\n", num_warning);

    fclose(file);

    if (line) {
        free(line);
    }

    return EXIT_SUCCESS;
}