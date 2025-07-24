//FormAI DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024
#define MAX_LOG_ENTRIES 100

struct LogEntry {
  int time;
  char message[MAX_LOG_SIZE];
};

struct LogFile {
  struct LogEntry entries[MAX_LOG_ENTRIES];
  int num_entries;
};

// Function to add a new log entry to the log file
void add_log_entry(struct LogFile* log_file, const char* message) {
  if (log_file->num_entries >= MAX_LOG_ENTRIES) {
    printf("Log file is full. Cannot add new entry.\n");
    return;
  }

  struct LogEntry* entry = &(log_file->entries[log_file->num_entries]);
  entry->time = time(NULL);
  strncpy(entry->message, message, MAX_LOG_SIZE);

  log_file->num_entries++;
}

// Function to print all log entries to the console
void print_log_entries(struct LogFile* log_file) {
  printf("Log file entries:\n");

  for (int i = 0; i < log_file->num_entries; i++) {
    struct LogEntry* entry = &(log_file->entries[i]);
    printf("%d: %s\n", entry->time, entry->message);
  }
}

int main() {
  struct LogFile log_file = {0};

  // Test adding log entries
  add_log_entry(&log_file, "Program started.");
  add_log_entry(&log_file, "Data initialized.");
  add_log_entry(&log_file, "User logged in.");
  add_log_entry(&log_file, "User logged out.");
  add_log_entry(&log_file, "Program terminated.");

  // Test printing log entries
  print_log_entries(&log_file);

  return 0;
}