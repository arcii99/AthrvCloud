//FormAI DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "apocalypse.log"
#define MAX_LINE_LENGTH 100

int main() {
    char line[MAX_LINE_LENGTH];
    int num_lines = 0, error_count = 0, warning_count = 0, info_count = 0, debug_count = 0;
    FILE *log_file = fopen(LOG_FILE, "r");

    if (!log_file) {
        printf("Log file not found!\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        num_lines++;

        if (strstr(line, "ERROR")) {
            error_count++;
            printf("[ERROR] %s", line);
        } else if (strstr(line, "WARNING")) {
            warning_count++;
            printf("[WARNING] %s", line);
        } else if (strstr(line, "INFO")) {
            info_count++;
            printf("[INFO] %s", line);
        } else if (strstr(line, "DEBUG")) {
            debug_count++;
            printf("[DEBUG] %s", line);
        }
    }

    fclose(log_file);
    
    // Add some randomness to the analysis
    srand(time(NULL));
    int rnd_num = rand() % 10;

    if (rnd_num < 3) {
        printf("It's the end of the world as we know it!\n");
        return 0;
    }

    printf("Log file analysis summary:\n");
    printf("- %d lines analyzed\n", num_lines);
    printf("- %d error(s)\n", error_count);
    printf("- %d warning(s)\n", warning_count);
    printf("- %d info message(s)\n", info_count);
    printf("- %d debug message(s)\n", debug_count);

    return 0;
}