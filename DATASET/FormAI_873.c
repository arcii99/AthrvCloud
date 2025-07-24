//FormAI DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LINE_LENGTH 1000
#define MAX_LOG_ARGUMENTS 10

// A struct to hold each log line and its arguments
typedef struct {
  char* line;
  char* arguments[MAX_LOG_ARGUMENTS];
  int num_arguments;
} LogLine;

// Function prototypes
void parse_log_file(const char* log_file, LogLine log_lines[], int* num_lines);
void print_log_lines(LogLine log_lines[], int num_lines);

int main() {
  LogLine log_lines[MAX_LOG_LINES]; // Array to hold log lines
  int num_lines = 0;

  // Parse the log file and store each log line in the log_lines array
  parse_log_file("example_log.txt", log_lines, &num_lines);

  // Print out the parsed log lines
  print_log_lines(log_lines, num_lines);

  return 0;
}

// Parses the log file and stores each log line in the log_lines array
void parse_log_file(const char* log_file, LogLine log_lines[], int* num_lines) {
  FILE* fp = fopen(log_file, "r");
  char line[MAX_LOG_LINE_LENGTH];

  if (fp != NULL) {
    while (fgets(line, sizeof(line), fp)) {
      LogLine log_line;
      log_line.line = strdup(line); // Store the log line itself
      log_line.num_arguments = 0;

      char* token = strtok(line, " "); // Split the log line on spaces
      while (token != NULL) {
        // Store each argument separately
        log_line.arguments[log_line.num_arguments] = strdup(token);
        log_line.num_arguments++;
        token = strtok(NULL, " ");
      }

      log_lines[*num_lines] = log_line;
      (*num_lines)++;
    }

    fclose(fp);
  }
}

// Prints out the parsed log lines
void print_log_lines(LogLine log_lines[], int num_lines) {
  for (int i = 0; i < num_lines; i++) {
    printf("Log Line %d:\n", i+1);
    printf("\tLine: %s\n", log_lines[i].line);
    printf("\tArguments (%d):\n", log_lines[i].num_arguments);
    for (int j = 0; j < log_lines[i].num_arguments; j++) {
      printf("\t\t%d. %s\n", j+1, log_lines[i].arguments[j]);
    }
  }
}