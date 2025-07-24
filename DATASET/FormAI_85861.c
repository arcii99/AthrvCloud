//FormAI DATASET v1.0 Category: Log analysis ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() {
  // Open the log file for reading
  FILE *log_file = fopen("my_log_file.txt", "r");

  // Check if the file was opened successfully
  if (log_file == NULL) {
    perror("Error opening file");
    return -1;
  }

  // Define variables to hold information about each log entry
  char timestamp[20];
  char log_level[10];
  char message[100];

  // Define variables to hold aggregated information
  int num_warnings = 0;
  int num_errors = 0;
  int num_fatal_errors = 0;
  int total_entries = 0;

  // Loop through each line in the log file
  while (fgets(timestamp, sizeof(timestamp), log_file) != NULL &&
         fgets(log_level, sizeof(log_level), log_file) != NULL &&
         fgets(message, sizeof(message), log_file) != NULL) {

    // Remove the trailing newline character from the message
    message[strcspn(message, "\n")] = '\0';

    // Count the total number of entries
    total_entries++;

    // Check if the log level is a warning, error, or fatal error
    if (strcmp(log_level, "WARNING\n") == 0) {
      num_warnings++;
    } else if (strcmp(log_level, "ERROR\n") == 0) {
      num_errors++;
    } else if (strcmp(log_level, "FATAL ERROR\n") == 0) {
      num_fatal_errors++;
    }
  }

  // Close the log file
  fclose(log_file);

  // Print the aggregated information
  printf("Total number of log entries: %d\n", total_entries);
  printf("Number of warnings: %d\n", num_warnings);
  printf("Number of errors: %d\n", num_errors);
  printf("Number of fatal errors: %d\n", num_fatal_errors);

  return 0;
}