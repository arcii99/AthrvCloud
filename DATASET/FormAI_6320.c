//FormAI DATASET v1.0 Category: System event logger ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event) {
  time_t now = time(NULL);
  char* timestamp = ctime(&now);
  timestamp[strlen(timestamp) - 1] = '\0';
  printf("[%s] %s\n", timestamp, event);
}

int main() {
  printf("Starting system event logger...\n");
  int count = 0;
  while (1) {
    char* event = malloc(sizeof(char) * 100);
    printf("Enter an event to log (or type 'exit' to quit): ");
    fgets(event, 100, stdin);
    event[strlen(event) - 1] = '\0';
    if (strcmp(event, "exit") == 0) {
      printf("Exiting system event logger...\n");
      break;
    }
    logEvent(event);
    count++;
    if (count % 5 == 0) {
      printf("So far, %d events have been logged.\n", count);
    }
    free(event);
  }
  return 0;
}