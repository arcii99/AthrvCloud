//FormAI DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LINE_LEN 100

/* Structure to hold individual log entries */
typedef struct log_entry {
    char timestamp[25];
    char severity;
    char source[50];
    char message[MAX_LOG_LINE_LEN];
} log_entry;

/* Function to parse a log file and populate an array of log_entry structures */
int parse_log_file(const char *filename, log_entry *log_entries) {
    FILE *log_file = fopen(filename, "r");
    if (log_file == NULL) {
        printf("Could not open log file %s\n", filename);
        return 0;
    }

    char line[MAX_LOG_LINE_LEN];
    int i = 0;
    while (fgets(line, MAX_LOG_LINE_LEN, log_file) != NULL && i < MAX_LOG_ENTRIES) {
        char *timestamp = strtok(line, ",");
        char *severity = strtok(NULL, ",");
        char *source = strtok(NULL, ",");
        char *message = strtok(NULL, ",");
        if (timestamp == NULL || severity == NULL || source == NULL || message == NULL) {
            printf("Error parsing log entry on line %d\n", i+1);
            continue;
        }
        strcpy(log_entries[i].timestamp, timestamp);
        log_entries[i].severity = severity[0];
        strcpy(log_entries[i].source, source);
        strcpy(log_entries[i].message, message);
        i++;
    }
    fclose(log_file);
    return i; // Return number of entries parsed
}

/* Function to filter log entries by specified severity level */
int filter_by_severity(log_entry *log_entries, int num_entries, char severity_level, log_entry **filtered_entries) {
    int num_filtered_entries = 0;
    for (int i = 0; i < num_entries; i++) {
        if (log_entries[i].severity == severity_level) {
            filtered_entries[num_filtered_entries++] = &log_entries[i];
        }
    }
    return num_filtered_entries;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please specify the path to the log file\n");
        return 1;
    }
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = parse_log_file(argv[1], log_entries);
    printf("Parsed %d log entries\n", num_entries);

    log_entry *filtered_entries[MAX_LOG_ENTRIES];
    int num_filtered_entries = filter_by_severity(log_entries, num_entries, 'E', filtered_entries);

    printf("Found %d log entries with severity level E:\n", num_filtered_entries);
    for (int i = 0; i < num_filtered_entries; i++) {
        printf("%s - %c - %s - %s", filtered_entries[i]->timestamp, filtered_entries[i]->severity,
                filtered_entries[i]->source, filtered_entries[i]->message);
    }

    return 0;
}