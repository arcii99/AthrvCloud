//FormAI DATASET v1.0 Category: Log analysis ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a log message
#define MAX_MESSAGE_LENGTH 100

// Define the maximum length of a log level
#define MAX_LEVEL_LENGTH 10

// Define the maximum number of entries in the log
#define MAX_ENTRIES 1000

// Define a struct to represent a single log entry
typedef struct LogEntry {
    char message[MAX_MESSAGE_LENGTH];
    char level[MAX_LEVEL_LENGTH];
    time_t timestamp;
} LogEntry;

// Define a struct to represent a log of multiple entries
typedef struct Log {
    int size;
    LogEntry entries[MAX_ENTRIES];
} Log;

// Define a function to print out a single log entry
void print_entry(LogEntry entry) {
    printf("[%s] %s - %s\n", ctime(&(entry.timestamp)), entry.level, entry.message);
}

// Define a function to add a new entry to an existing log
void add_entry(Log* log, char* message, char* level) {
    // Create a new log entry
    LogEntry new_entry;
    strcpy(new_entry.message, message);
    strcpy(new_entry.level, level);
    new_entry.timestamp = time(NULL);

    // Add the new entry to the log and increment the size
    log->entries[log->size] = new_entry;
    log->size++;
}

// Define the main function to run the program
int main() {
    // Create a new log
    Log my_log;
    my_log.size = 0;

    // Add some entries to the log
    add_entry(&my_log, "Program started", "INFO");
    add_entry(&my_log, "This is a warning message", "WARNING");
    add_entry(&my_log, "The program encountered an error", "ERROR");

    // Print out each entry in the log
    for (int i = 0; i < my_log.size; i++) {
        print_entry(my_log.entries[i]);
    }

    return 0;
}