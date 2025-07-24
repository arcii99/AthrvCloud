//FormAI DATASET v1.0 Category: Log analysis ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE_SIZE 256

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s log_file_path\n", argv[0]);
        return EXIT_FAILURE;
    }
    char* log_file_path = argv[1];
    FILE* log_file = fopen(log_file_path, "r");
    if (!log_file) {
        printf("Error: unable to open log file %s\n", log_file_path);
        return EXIT_FAILURE;
    }
    char* line_buffer = malloc(sizeof(char) * MAX_LINE_SIZE);
    if (!line_buffer) {
        printf("Error: unable to allocate line buffer\n");
        fclose(log_file);
        return EXIT_FAILURE;
    }
    int line_number = 0;
    int total_lines = 0;
    int http_ok_count = 0;
    while (fgets(line_buffer, MAX_LINE_SIZE, log_file)) {
        total_lines++;
        line_number++;
        char* http_ok_str = strstr(line_buffer, "HTTP/1.1\" 200");
        if (http_ok_str) {
            http_ok_count++;
            printf("Line %d contains HTTP 200 OK response: %s", line_number, line_buffer);
        }
    }
    printf("Total lines: %d\n", total_lines);
    printf("HTTP 200 OK count: %d\n", http_ok_count);
    fclose(log_file);
    free(line_buffer);
    return EXIT_SUCCESS;
}