//FormAI DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max length of log entries
#define MAX_LOG_LEN 100

// Define struct for log entry
typedef struct log_entry {
    char timestamp[25];
    char message[MAX_LOG_LEN];
} log_entry_t;

int main(void) {
    // Create array of log entries
    log_entry_t logs[10];

    // Add dummy logs
    strcpy(logs[0].timestamp, "21-01-2200 12:05:23");
    strcpy(logs[0].message, "System boot successful");
    strcpy(logs[1].timestamp, "21-01-2200 12:10:45");
    strcpy(logs[1].message, "User login from IP 192.168.0.1");
    strcpy(logs[2].timestamp, "21-01-2200 13:20:15");
    strcpy(logs[2].message, "File saved successfully to /root/future/plans.doc");
    strcpy(logs[3].timestamp, "21-01-2200 13:25:32");
    strcpy(logs[3].message, "Warning: CPU usage exceeded 90%");
    strcpy(logs[4].timestamp, "21-01-2200 13:30:06");
    strcpy(logs[4].message, "Error: Failed to establish connection with database");

    // Define variables for analysis
    int count_warning = 0;
    int count_error = 0;
    int count_successful = 0;
    int count_failed = 0;

    // Analyze logs
    for (int i = 0; i < 5; i++) {
        if (strstr(logs[i].message, "Warning") != NULL) {
            count_warning++;
        } else if (strstr(logs[i].message, "Error") != NULL) {
            count_error++;
        } else if (strstr(logs[i].message, "successful") != NULL) {
            count_successful++;
        } else if (strstr(logs[i].message, "failed") != NULL) {
            count_failed++;
        }
    }

    // Print analysis results
    printf("*** Log Analysis Results ***\n");
    printf("Number of warnings: %d\n", count_warning);
    printf("Number of errors: %d\n", count_error);
    printf("Number of successful operations: %d\n", count_successful);
    printf("Number of failed operations: %d\n", count_failed);

    // Exit program
    return 0;
}