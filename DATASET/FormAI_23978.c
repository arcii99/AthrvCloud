//FormAI DATASET v1.0 Category: Log analysis ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_LOG_ENTRIES 100

typedef struct LogEntry {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_SIZE];
} LogEntry;

int main() {
    FILE *log_file = fopen("application.log", "r");
    if (log_file == NULL) {
        printf("Error: Cannot open log file.\n");
        exit(EXIT_FAILURE);
    }

    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, log_file) != NULL) {

        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Warning: Maximum log entries reached.\n");
            break;
        }

        char* t = strtok(line, " ");
        int token_count = 0;
        while (t && token_count < 3) {
            if (token_count == 0) {
                strcpy(log_entries[num_entries].timestamp, t);
            }
            else if (token_count == 1) {
                strcpy(log_entries[num_entries].level, t);
            }
            else if (token_count == 2) {
                strcpy(log_entries[num_entries].message, t);
            }

            t = strtok(NULL, " ");
            token_count++;
        }

        num_entries++;
    }

    fclose(log_file);

    printf("Timestamp\t\tLevel\t\tMessage\n");
    printf("---------\t\t-----\t\t-------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\n", log_entries[i].timestamp, log_entries[i].level, log_entries[i].message);
    }

    return EXIT_SUCCESS;
}