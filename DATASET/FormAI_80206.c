//FormAI DATASET v1.0 Category: Log analysis ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_LOG_ENTRIES 1000

/*
    Struct to hold a single log entry
*/
typedef struct {
    char* timestamp;
    char* message;
} LogEntry;

/*
    Struct to hold all the log entries
*/
typedef struct {
    int num_entries;
    LogEntry entries[MAX_LOG_ENTRIES];
} Log;

/*
    Function to parse a single log entry from a line of text
*/
LogEntry parse_log_entry(char* line) {
    LogEntry entry;
    entry.timestamp = strtok(line, "|");
    entry.message = strtok(NULL, "\n");
    return entry;
}

/*
    Function to read in all the log entries from a file
*/
Log read_log_file(char* filename) {
    Log log;
    log.num_entries = 0;

    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while(fgets(line, sizeof(line), file) != NULL) {
        log.entries[log.num_entries++] = parse_log_entry(line);
    }

    fclose(file);
    return log;
}

/*
    Function to print out all the log entries in the log
*/
void print_log(Log log) {
    for(int i = 0; i < log.num_entries; i++) {
        printf("%s | %s\n", log.entries[i].timestamp, log.entries[i].message);
    }
}

/*
    Function to count the number of occurrences of a given string
    in the log messages
*/
int count_string_occurrences(Log log, char* string) {
    int count = 0;
    for(int i = 0; i < log.num_entries; i++) {
        if(strstr(log.entries[i].message, string) != NULL) {
            count++;
        }
    }
    return count;
}

int main() {
    Log log = read_log_file("example.log");
    print_log(log);

    int num_errors = count_string_occurrences(log, "ERROR");
    printf("Number of errors: %d\n", num_errors);

    return 0;
}