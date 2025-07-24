//FormAI DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("\n\n ********** Cyberpunk Style C Log Analysis ********** \n\n");

    FILE *log_file;
    char log_line[100];
    char *log_file_name = "cyber.log";
    int line_count = 0;
    int error_count = 0;
    char error_message[100];

    log_file = fopen(log_file_name, "r");

    if (log_file == NULL) {
        printf("Error opening log file\n");
        exit(0);
    }

    printf("Analyzing log file...\n\n");

    while (fgets(log_line, 100, log_file)) {
        line_count++;

        if (strstr(log_line, "ERROR") != NULL) {
            error_count++;
            strcpy(error_message, log_line);
            printf("ALERT: Error detected on line %d - %s", line_count, error_message);
        }
    }

    if (error_count == 0) {
        printf("No errors detected in log file\n");
    }

    printf("\n\n ********** End of Log Analysis **********\n\n");
    fclose(log_file);
    return 0;
}