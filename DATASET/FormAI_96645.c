//FormAI DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_log(char* message) {
    // Output the formatted log message to the console
    printf("LOG: %s\n", message);
}

int main() {
    // Read in the log file and store it as a string
    FILE* file = fopen("example.log", "r");
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* log_data = malloc(size);
    fread(log_data, 1, size, file);
    fclose(file);

    // Split the log data into individual lines
    char* line_start = log_data;
    char* line_end = strstr(log_data, "\n");
    while (line_end != NULL) {
        // Extract the log message from each line
        int message_length = line_end - line_start;
        char* message = malloc(message_length);
        strncpy(message, line_start, message_length);
        message[message_length] = '\0';

        // Output the log message to the console
        print_log(message);

        // Move to the next line in the log data
        line_start = line_end + 1;
        line_end = strstr(line_start, "\n");
    }

    return 0;
}