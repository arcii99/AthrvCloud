//FormAI DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_error(const char *error_msg) {
    fprintf(stderr, "Error: %s\n", error_msg);

    // Optionally, we could log the error and/or send it to a monitoring service.

    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        handle_error("Not enough arguments provided.");
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        char err_msg[100];
        snprintf(err_msg, sizeof(err_msg), "Could not open file '%s'", argv[1]);
        handle_error(err_msg);
    }

    int num_lines = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        num_lines++;

        if (num_lines > 100) { // arbitrary limit
            handle_error("File has too many lines (> 100)");
        }

        size_t line_len = strlen(line);

        if (line_len == sizeof(line) - 1 && line[line_len - 1] != '\n') {
            handle_error("Line is too long. Max length is 99 characters.");
        }
    }

    printf("File has %d lines.", num_lines);

    fclose(file);

    return 0;
}