//FormAI DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>

int main() {
    FILE *log_file;
    char log_line[1000];
    int num_lines = 0;
    int num_404s = 0;
    int num_200s = 0;
    int i;

    log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fgets(log_line, 1000, log_file) != NULL) {
        num_lines++;

        // Check for 404 errors
        if (strstr(log_line, "404") != NULL) {
            num_404s++;
            printf("Line %d: 404 Error Found!\n", num_lines);
        }

        // Check for 200 status codes
        if (strstr(log_line, " 200 ") != NULL) {
            num_200s++;
        }
    }

    printf("\n\n\n");
    printf("Log Analysis Results:\n");
    printf("---------------------\n");
    printf("Total number of lines: %d\n", num_lines);
    printf("Number of 404 Errors: %d\n", num_404s);
    printf("Number of 200 OK Status Codes: %d\n", num_200s);
    printf("\n\n\n");

    fseek(log_file, 0, SEEK_SET);

    printf("Here are the last 10 lines of the log file:\n\n");

    for (i = 0; i < num_lines; i++) {
        if (fgets(log_line, 1000, log_file) == NULL) {
            break;
        }

        if (i >= num_lines - 10) {
            printf("%s", log_line);
        }
    }

    fclose(log_file);

    return 0;
}