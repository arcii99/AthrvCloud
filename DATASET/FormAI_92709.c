//FormAI DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *logfile;
    char *line;
    size_t len = 0;
    ssize_t read;
    int suspicious = 0; // A flag to track suspicious activity
    
    logfile = fopen("example.log", "r");

    if (logfile == NULL) {
        printf("Could not open log file!\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, logfile)) != -1) {
        // Check for SQL injection attempt
        if (strstr(line, "SELECT * FROM") != NULL && strstr(line, "WHERE") == NULL) {
            printf("WARNING: Possible SQL injection attempt! Check log for more details.\n");
            suspicious = 1;
        }
        // Check for directory traversal attempt
        if (strstr(line, "../") != NULL) {
            printf("WARNING: Possible directory traversal attempt! Check log for more details.\n");
            suspicious = 1;
        }
        // Check for unusual user activity
        if (strstr(line, "root") != NULL && strstr(line, "sudo") == NULL) {
            printf("WARNING: Suspicious user activity detected! Check log for more details.\n");
            suspicious = 1;
        }
    }

    if (suspicious == 0) {
        printf("No suspicious activity detected in log file.\n");
    } else {
        printf("Please investigate suspicious activity in log file.\n");
    }

    fclose(logfile);
    if (line) {
        free(line);
    }
    exit(EXIT_SUCCESS);
}