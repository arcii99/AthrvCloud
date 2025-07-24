//FormAI DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_SIZE 1024

int main(int argc, char **argv) {
    FILE *file = fopen(argv[1], "r"); //Open the log file
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    char *line_buffer = (char*)malloc(MAX_LINE_SIZE); //Allocate memory for each line read from the log file
    if (line_buffer == NULL) {
        printf("Failed to allocate line buffer\n");
        return 1;
    }

    int total_lines = 0;
    int error_count = 0;
    int warning_count = 0;
    int info_count = 0;

    while (fgets(line_buffer, MAX_LINE_SIZE, file) != NULL) {
        total_lines++;

        if (strstr(line_buffer, "[ERROR]")) {
            error_count++;
        } else if (strstr(line_buffer, "[WARNING]")) {
            warning_count++;
        } else if (strstr(line_buffer, "[INFO]")) {
            info_count++;
        }
    }

    printf("Total number of lines: %d\n", total_lines);
    printf("Number of ERROR lines: %d\n", error_count);
    printf("Number of WARNING lines: %d\n", warning_count);
    printf("Number of INFO lines: %d\n", info_count);

    fclose(file);
    free(line_buffer);
    return 0;
}