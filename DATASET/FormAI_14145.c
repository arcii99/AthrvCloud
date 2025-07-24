//FormAI DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_EVENT_LENGTH 50
#define MAX_NUM_EVENTS 100

struct Event {
  char timestamp[20];
  char name[MAX_EVENT_LENGTH];
};

void logEvent(char *eventName, struct Event *events, int *numEvents) {
  time_t now;
  struct tm *localTime;
  time(&now);
  localTime = localtime(&now);
  sprintf(events[*numEvents].timestamp, "%02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
  strcpy(events[*numEvents].name, eventName);
  (*numEvents)++;
}

void printEvents(struct Event *events, int numEvents) {
  printf("----------------------------\n");
  printf("|  Timestamp  |   Event   |\n");
  printf("----------------------------\n");
  for (int i = 0; i < numEvents; i++) {
    printf("| %10s  |  %-10s |\n", events[i].timestamp, events[i].name);
  }
  printf("----------------------------\n");
}

int main() {
  int numEvents = 0;
  struct Event events[MAX_NUM_EVENTS];

  // Log some events
  logEvent("System Starting", events, &numEvents);
  logEvent("Initialized Network Connections", events, &numEvents);
  logEvent("Started Main Loop", events, &numEvents);
  logEvent("Received SIGNAL Interrupt", events, &numEvents);
  logEvent("Closed Network Connections", events, &numEvents);
  logEvent("System Exiting", events, &numEvents);

  // Display all events
  printEvents(events, numEvents);

  return 0;
}