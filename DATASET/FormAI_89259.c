//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000

struct log_entry {
  char timestamp[20];
  char source_address[16];
  char message[100];
};

struct log_entry log_entries[MAX_LOG_ENTRIES];
int num_entries = 0;

void log_entry(char *source_address, char *message) {
  time_t now = time(NULL);
  struct tm *local_time = localtime(&now);
  char timestamp[20];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", local_time);

  struct log_entry entry;
  strcpy(entry.timestamp, timestamp);
  strcpy(entry.source_address, source_address);
  strcpy(entry.message, message);

  if (num_entries < MAX_LOG_ENTRIES) {
    log_entries[num_entries++] = entry;
  }
}

void check_logs(char *source_address) {
  int num_attempts = 0;
  int num_fails = 0;
  int num_successes = 0;

  for (int i = 0; i < num_entries; i++) {
    struct log_entry entry = log_entries[i];

    if (strcmp(entry.source_address, source_address) == 0) {
      num_attempts++;

      if (strstr(entry.message, "failed login") != NULL) {
        num_fails++;
      } else if (strstr(entry.message, "successful login") != NULL) {
        num_successes++;
      }
    }
  }

  if (num_attempts > 5 && ((float)num_fails / num_attempts) > 0.5) {
    printf("Potential intrusion detected from %s\n", source_address);
  }
}

int main(void) {
  log_entry("192.168.1.1", "failed login");
  log_entry("192.168.1.1", "failed login");
  log_entry("192.168.1.1", "failed login");
  log_entry("192.168.1.1", "successful login");
  log_entry("192.168.1.1", "failed login");
  log_entry("192.168.1.1", "failed login");

  check_logs("192.168.1.1");

  log_entry("192.168.1.1", "successful login");
  log_entry("192.168.1.1", "failed login");
  log_entry("192.168.1.1", "successful login");
  log_entry("192.168.1.1", "failed login");
  log_entry("192.168.1.1", "successful login");

  check_logs("192.168.1.1");

  return 0;
}