//FormAI DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
   
    char* filename = "logfile.txt";
    FILE* log_file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    int line_counter = 0;
    int error_counter = 0;
    int warning_counter = 0;

    if (!log_file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, log_file)) {
        line_counter++;

        if (strstr(buffer, "ERROR")) {
            error_counter++;
            printf("Error found on line %d: %s", line_counter, buffer);
        } else if (strstr(buffer, "WARNING")) {
            warning_counter++;
            printf("Warning found on line %d: %s", line_counter, buffer);
        }
    }

    fclose(log_file);

    printf("Log analysis complete\n");
    printf("%d lines analyzed\n", line_counter);
    printf("%d errors found\n", error_counter);
    printf("%d warnings found\n", warning_counter);

    return 0;
}