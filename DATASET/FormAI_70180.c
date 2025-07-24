//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define CPUSTAT "/proc/stat"

void print_header() {
  printf("---------------------------------------------------\n");
  printf("           CPU Usage Monitor by HappyBot           \n");
  printf("---------------------------------------------------\n");
}

void print_usage(float usage) {
  printf("Current CPU Usage: %.2f %%\n", usage);
}

float calculate_usage(unsigned long long* prev_vals, unsigned long long* curr_vals) {
  unsigned long long prev_total = 0, curr_total = 0;
  unsigned long long prev_idle = 0, curr_idle = 0;
  float usage;

  for (int i = 0; i < 10; i++) {
    prev_total += prev_vals[i];
    curr_total += curr_vals[i];
    if (i == 3) {
      prev_idle = prev_vals[i];
      curr_idle = curr_vals[i];
    }  
  }
  unsigned long long diff_idle = curr_idle - prev_idle;
  unsigned long long diff_total = curr_total - prev_total;
  usage = 100.0 * (diff_total - diff_idle) / diff_total;
  return usage;
}

void collect_stats(unsigned long long* vals) {
  int fd = open(CPUSTAT, O_RDONLY);
  char buffer[1024];
  read(fd, buffer, 1024);
  close(fd);
  char* line = strtok(buffer, "\n");
  int i = 0;
  while (line != NULL) {
    if (strncmp(line, "cpu", 3) == 0) {
      char* token = strtok(line + 3, " ");
      while (token != NULL) {
        vals[i] = strtoull(token, NULL, 10);
        token = strtok(NULL, " ");
        i++;
      }
    }
    line = strtok(NULL, "\n");
  }
}

int main() {
  unsigned long long prev_vals[11];
  unsigned long long curr_vals[11];
  print_header();
  while(1) {
    collect_stats(prev_vals);
    usleep(1000000);
    collect_stats(curr_vals);
    print_usage(calculate_usage(prev_vals, curr_vals));
    memcpy(prev_vals, curr_vals, sizeof(curr_vals));
  }
  return 0;
}