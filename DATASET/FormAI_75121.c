//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

typedef struct {
  char ip_address[16];
  char timestamp[20];
  char action[10];
} LogEntry;

void checkAuthorization(char* ip_address) {
  // Perform authorization check here
  printf("Authorization check for %s\n", ip_address);
}

void logActivity(char* ip_address, char* action) {
  // Log activity in system log file
  printf("Logging activity for %s: %s\n", ip_address, action);
}

int main() {
  LogEntry log_entries[MAX_INPUT_SIZE];
  char input[MAX_INPUT_SIZE];
  int num_entries = 0;

  printf("Welcome to the Intrusion Detection System!\n");

  while (1) {
    printf("Enter log entry (or type 'q' to quit):\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    if (strcmp(input, "q\n") == 0) {
      break;
    }

    char* token = strtok(input, ",");
    int i = 0;
    while (token != NULL) {
      if (i == 0) {
        strcpy(log_entries[num_entries].ip_address, token);
        checkAuthorization(log_entries[num_entries].ip_address);
      } else if (i == 1) {
        strcpy(log_entries[num_entries].timestamp, token);
      } else if (i == 2) {
        strcpy(log_entries[num_entries].action, token);
        logActivity(log_entries[num_entries].ip_address, log_entries[num_entries].action);
      }
      token = strtok(NULL, ",");
      i++;
    }
    num_entries++;
  }

  printf("Intrusion Detection System shutting down.\n");
  return 0;
}