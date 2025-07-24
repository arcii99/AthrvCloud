//FormAI DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>

int main() {

    // Artistic variable declarations
    FILE *log_file;
    char log_line[100];
    int total_logs = 0;

    // Open log file
    log_file = fopen("example_log.txt", "r");

    // Check if file was opened successfully
    if (log_file == NULL) {
        printf("Error opening log file!");
        return 1;
    }

    // Iterate through each line in the log file
    while (fgets(log_line, 100, log_file)) {

        // Artistic log parsing
        char log_time[10];
        char log_type[10];
        char log_message[80];
        sscanf(log_line, "%[^,],%[^,],%[^\n]", log_time, log_type, log_message);

        // Artistic log analysis
        if (strcmp(log_type, "ERROR") == 0) {
            printf("Error detected at %s: %s\n", log_time, log_message);
        } else if (strcmp(log_type, "WARNING") == 0) {
            printf("Warning detected at %s: %s\n", log_time, log_message);
        } else {
            printf("Info logged at %s: %s\n", log_time, log_message);
        }

        total_logs++;

    }

    // Artistic program summary
    printf("\nTotal logs analyzed: %d\n", total_logs);

    // Close log file
    fclose(log_file);

    return 0;
}