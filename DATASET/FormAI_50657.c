//FormAI DATASET v1.0 Category: System event logger ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define a struct to hold the log entries
typedef struct {
    time_t timestamp;
    char *message;
} LogEntry;

// Define a function to write a log entry to a file
void write_to_log(LogEntry entry) {
    FILE *logfile = fopen("system.log", "a");
    if (logfile == NULL) {
        printf("Error opening log file.\n");
        return;
    }
    fprintf(logfile, "[%ld] %s\n", entry.timestamp, entry.message);
    fclose(logfile);
}

// Define a function to create a log entry
LogEntry create_entry(char *message) {
    LogEntry entry;
    entry.timestamp = time(NULL);
    entry.message = malloc(strlen(message) + 1);
    strcpy(entry.message, message);
    return entry;
}

int main() {
    // Log a process start event
    LogEntry entry = create_entry("Process started: example_process");
    write_to_log(entry);
    
    // Log a file modification event
    entry = create_entry("File modified: /path/to/file.txt");
    write_to_log(entry);
    
    // Log a network connection event
    entry = create_entry("Network connection established: 192.168.0.1");
    write_to_log(entry);
    
    return 0;
}