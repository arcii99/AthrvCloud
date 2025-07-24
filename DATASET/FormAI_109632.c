//FormAI DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *filename = "server.log";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int warning_count = 0;
    int error_count = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        char *level_str = strtok(line, " ");
        if (strcmp(level_str, "WARNING") == 0) {
            warning_count++;
        } else if (strcmp(level_str, "ERROR") == 0) {
            error_count++;
        }
    }

    printf("Log analysis of file '%s':\n", filename);
    printf("\t%d warnings\n", warning_count);
    printf("\t%d errors\n", error_count);

    fclose(file);
    if (line) {
        free(line);
    }

    return 0;
}