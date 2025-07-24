//FormAI DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char timestamp[20];
    char server_name[50];
    char message_level[10];
    char message[300];
} LogEntry;

int main() {
    FILE* logfile = fopen("server_log.txt", "r");
    if (logfile == NULL) {
        printf("Error: could not open logfile\n");
        return 1;
    }

    // Count the number of entries in the log file
    int num_entries = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, logfile) != NULL) {
        num_entries++;
    }

    // Allocate memory for the log entries
    LogEntry* entries = malloc(num_entries * sizeof(LogEntry));
    rewind(logfile);

    // Read each entry from the log file
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, logfile) != NULL) {
        sscanf(line, "%s %s %s %[^\n]", entries[i].timestamp, entries[i].server_name, entries[i].message_level, entries[i].message);
        i++;
    }

    // Close the log file
    fclose(logfile);

    // Analyze the log entries
    int num_fatal_errors = 0;
    int num_warnings = 0;
    int num_info_messages = 0;
    int num_debug_messages = 0;
    char server_names[50][50] = {0};
    int num_unique_servers = 0;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].message_level, "FATAL") == 0) {
            num_fatal_errors++;
        } else if (strcmp(entries[i].message_level, "WARNING") == 0) {
            num_warnings++;
        } else if (strcmp(entries[i].message_level, "INFO") == 0) {
            num_info_messages++;
        } else if (strcmp(entries[i].message_level, "DEBUG") == 0) {
            num_debug_messages++;
        }

        int server_name_exists = 0;
        for (int j = 0; j < num_unique_servers; j++) {
            if (strcmp(entries[i].server_name, server_names[j]) == 0) {
                server_name_exists = 1;
                break;
            }
        }
        if (!server_name_exists) {
            strcpy(server_names[num_unique_servers], entries[i].server_name);
            num_unique_servers++;
        }
    }

    // Print the analysis results
    printf("Log Analysis Results:\n");
    printf("---------------------\n");
    printf("Number of Fatal Errors: %d\n", num_fatal_errors);
    printf("Number of Warnings: %d\n", num_warnings);
    printf("Number of Info Messages: %d\n", num_info_messages);
    printf("Number of Debug Messages: %d\n", num_debug_messages);
    printf("Number of Unique Servers: %d\n", num_unique_servers);

    return 0;
}