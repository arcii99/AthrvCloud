//FormAI DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <string.h>

// Define a struct to store log information
struct LogEntry {
  char level[10];
  char timestamp[20];
  char message[100];
};

// Read log entries from a file and store them in an array of structs
int readLogEntries(FILE* file, struct LogEntry entries[]) {
  char line[200];
  int numEntries = 0;

  while (fgets(line, 200, file) != NULL) {
    if (strstr(line, "ERROR") != NULL || strstr(line, "INFO") != NULL) {
      // Parse the log entry and store it in the array
      char* token = strtok(line, " ");
      strcpy(entries[numEntries].timestamp, token);
      
      token = strtok(NULL, " ");
      strcpy(entries[numEntries].level, token);
      
      token = strtok(NULL, "\n");
      strcpy(entries[numEntries].message, token);
      
      numEntries++;
    }
  }

  return numEntries;
}

// Print out all log entries that match the given filter
void printMatchingEntries(struct LogEntry entries[], int numEntries, char* filter) {
  for (int i = 0; i < numEntries; i++) {
    if (strstr(entries[i].message, filter) != NULL) {
      printf("%s %s - %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
    }
  }
}

int main() {
  // Open the log file for reading
  FILE* file = fopen("logfile.txt", "r");
  if (file == NULL) {
    printf("Error: Unable to open file\n");
    return 1;
  }

  // Read the log entries from the file
  struct LogEntry entries[100];
  int numEntries = readLogEntries(file, entries);

  // Close the file
  fclose(file);

  // Print out all ERROR level log entries
  printf("ERRORS:\n");
  printMatchingEntries(entries, numEntries, "ERROR");

  // Print out all INFO level log entries that contain the word "login"
  printf("\nINFO - LOGIN EVENTS:\n");
  printMatchingEntries(entries, numEntries, "login");

  return 0;
}