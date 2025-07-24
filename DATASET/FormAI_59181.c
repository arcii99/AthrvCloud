//FormAI DATASET v1.0 Category: Log analysis ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size for log message
#define MAX_LOG_SIZE 500

// Define structure for log entries
typedef struct {
    int log_num;
    char message[MAX_LOG_SIZE];
} log_entry;

// Define function to read log entries from file
void read_logs_from_file(log_entry *logs, int *num_logs) {
    FILE *file = fopen("log_file.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open log file\n");
        exit(1);
    }

    int count = 0;
    while (fgets(logs[count].message, MAX_LOG_SIZE, file)) {
        logs[count].log_num = count + 1;
        count++;
    }
    *num_logs = count;
    fclose(file);
}

// Define function to search for logs containing a specific string
void search_logs(log_entry *logs, int num_logs, char *search_string) {
    int count = 0;
    for (int i = 0; i < num_logs; i++) {
        if (strstr(logs[i].message, search_string)) {
            printf("Log #%d: %s", logs[i].log_num, logs[i].message);
            count++;
        }
    }
    if (count == 0) {
        printf("No logs found containing '%s'\n", search_string);
    }
}

int main() {
    printf("Welcome to the Log Analyzer!\n");

    log_entry logs[100];
    int num_logs;

    // Read log entries from file
    read_logs_from_file(logs, &num_logs);

    // Print out total number of logs read from file
    printf("Read %d log entries from file\n", num_logs);

    // Prompt user to enter search string
    char search_string[MAX_LOG_SIZE];
    printf("Enter search string: ");
    fgets(search_string, MAX_LOG_SIZE, stdin);

    // Search for logs containing the search string
    search_logs(logs, num_logs, search_string);

    printf("Thank you for using the Log Analyzer!");
    return 0;
}