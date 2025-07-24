//FormAI DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct log_data {
  char event_type[20];
  char description[100];
  time_t timestamp;
};

struct log_data logs[100];
int num_logs = 0;

void log_event(char event_type[20], char description[100]) {
  time_t now = time(NULL);
  struct tm *t = localtime(&now);

  logs[num_logs].timestamp = now;
  strcpy(logs[num_logs].event_type, event_type);
  strcpy(logs[num_logs].description, description);

  // Print message to console
  printf("[%02d:%02d:%02d] %s: %s\n", t->tm_hour, t->tm_min, t->tm_sec, event_type, description);

  num_logs++;
}

int main() {
  log_event("INFO", "Starting program.");

  int x = 5;
  log_event("DEBUG", "Value of x is 5.");

  char message[100] = "Hello world!";
  log_event("DEBUG", "Message variable initialized.");

  for (int i = 0; i < strlen(message); i++) {
    printf("%c ", message[i]);
  }
  printf("\n");

  log_event("INFO", "Program complete.");

  return 0;
}