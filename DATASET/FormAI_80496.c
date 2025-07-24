//FormAI DATASET v1.0 Category: System event logger ; Style: accurate
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void logEvent(const char* event);

int main() {
  printf("Welcome to the Event Logger Program\n\n");

  char input[50];

  while (1) {
    printf("Enter an event to log (or type 'exit' to quit): ");
    scanf("%s", input);

    if (strcmp(input, "exit") == 0) {
      break;
    }

    logEvent(input);
  }

  printf("\nThank you for using the Event Logger Program!\n");

  return 0;
}

void logEvent(const char* event) {
  time_t now;
  time(&now);
  struct tm* timeinfo = localtime(&now);

  FILE* file = fopen("event_log.txt", "a");

  fprintf(file, "[%d-%02d-%02d %02d:%02d:%02d] %s\n",
    timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
    timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, event);

  fclose(file);

  printf("Logged event: %s\n", event);
}