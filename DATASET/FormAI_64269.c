//FormAI DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_EVENTS 10000

struct event {
  int id;
  char name[50];
  time_t time_stamp;  
};

struct logger {
  FILE *file;
  int event_count;
  struct event events[MAX_EVENTS];
};

struct logger *open_logger(char *file_name) {
  struct logger *logger = malloc(sizeof(struct logger));
  logger->file = fopen(file_name, "w");
  logger->event_count = 0;
  return logger;
}

void log_event(struct logger *logger, char *name) {
  if (logger->event_count == MAX_EVENTS) {
    printf("Max events reached, cannot log more events.\n");
    return;
  }
  struct event new_event = { logger->event_count++, "", time(NULL) };
  snprintf(new_event.name, sizeof(new_event.name), "%s", name);
  logger->events[logger->event_count - 1] = new_event;
  fprintf(logger->file, "%d %s %ld\n", new_event.id, new_event.name, new_event.time_stamp);
}

void close_logger(struct logger *logger) {
  fprintf(logger->file, "Logger closed\n");
  fclose(logger->file);
}

int main() {
  printf("Starting event logger...\n");
  printf("Opening logger file...\n");
  struct logger *logger = open_logger("event.log");
  printf("Logging some events...\n");
  log_event(logger, "Started logger");
  log_event(logger, "Performed some tasks");
  log_event(logger, "Sleeping for 10 seconds");
  sleep(10);
  log_event(logger, "Woke up from sleep");
  printf("Closing logger...\n");
  close_logger(logger);
  printf("Event logger closed.\n");
  return 0;
}