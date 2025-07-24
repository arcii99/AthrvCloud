//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_LENGTH 1024
#define UPDATE_INTERVAL 1 // in seconds

void print_usage(float usage) {
  printf("Current RAM Usage: %0.2f%%\n", usage);
}

int main(int argc, char *argv[]) {
  unsigned long long total_memory;

  // get total memory available
  struct sysinfo s_info;
  sysinfo(&s_info);
  total_memory = (unsigned long long)s_info.totalram * (unsigned long long)s_info.mem_unit;

  // initialize memory usage variables
  unsigned long long used_memory = 0;
  char buffer[MAX_LENGTH];

  while (1) {
    // open the proc meminfo file
    FILE *file = fopen("/proc/meminfo", "r");

    if (file != NULL) {
      while (fgets(buffer, MAX_LENGTH, file)) {
        // get the line that contains the total memory usage
        if (strstr(buffer, "MemTotal:") != NULL) {
          unsigned long long temp;
          sscanf(buffer, "MemTotal: %llu", &temp);
        } else if (strstr(buffer, "Active:") != NULL) { // get active memory
          unsigned long long temp;
          sscanf(buffer, "Active: %llu", &temp);
          used_memory += temp * 1024;
        } else if (strstr(buffer, "Inactive:") != NULL) { // get inactive memory
          unsigned long long temp;
          sscanf(buffer, "Inactive: %llu", &temp);
          used_memory += temp * 1024;
        }
      }
      fclose(file);

      float usage = ((float)used_memory / (float)total_memory) * 100.0f;
      print_usage(usage);
    }

    sleep(UPDATE_INTERVAL);
  }

  return 0;
}