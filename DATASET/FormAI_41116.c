//FormAI DATASET v1.0 Category: System event logger ; Style: decentralized
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// Struct that represents a log event
struct log_entry_t {
    char timestamp[26];
    char message[256];
};

// Function to write log events to file
void write_to_file(char* filename, struct log_entry_t log_entry) {
    FILE* fptr;

    // Open file in append mode
    fptr = fopen(filename, "a");

    // Write log entry to file
    fprintf(fptr, "[%s] %s\n", log_entry.timestamp, log_entry.message);

    // Close file
    fclose(fptr);
}

// Function to generate current timestamp
void generate_timestamp(char* timestamp) {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    strftime(timestamp, 26, "%Y-%m-%d %H:%M:%S", tm);
}

int main() {
    char filename[256] = "system.log";
    struct log_entry_t log_entry;

    // Generate sample log events
    strcpy(log_entry.message, "System started successfully");
    generate_timestamp(log_entry.timestamp);
    write_to_file(filename, log_entry);

    strcpy(log_entry.message, "Database server started");
    generate_timestamp(log_entry.timestamp);
    write_to_file(filename, log_entry);

    strcpy(log_entry.message, "Web server started");
    generate_timestamp(log_entry.timestamp);
    write_to_file(filename, log_entry);

    strcpy(log_entry.message, "Error: Unable to connect to database");
    generate_timestamp(log_entry.timestamp);
    write_to_file(filename, log_entry);

    // Exit program
    return 0;
}