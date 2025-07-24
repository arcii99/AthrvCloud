//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 1024

double calculate_cpu_usage(unsigned long long int* prev_idle, unsigned long long int* prev_total) {
  FILE *fp;
  char buffer[BUF_SIZE];
  unsigned long long int idle, total;
  double cpu_load;

  fp = fopen("/proc/stat", "r");
  if(fp == NULL) {
    fprintf(stderr, "Error opening /proc/stat file.\n");
    return -1;
  }

  fgets(buffer, BUF_SIZE, fp);
  char* tok = strtok(buffer, " ");
  for (int i = 0; i < 5; i++) {
    tok = strtok(NULL, " ");
  }
  idle = atoll(tok);

  total = 0;
  while (tok != NULL) {
    tok = strtok(NULL, " ");
    if (tok != NULL) {
      total += atoll(tok);
    }
  }

  fclose(fp);

  unsigned long long int total_diff = total - (*prev_total);
  unsigned long long int idle_diff = idle - (*prev_idle);
  cpu_load = (((double)(total_diff - idle_diff))/total_diff) * 100;
  *prev_total = total;
  *prev_idle = idle;

  return cpu_load;
}

void sleep_time(struct timespec* ts, int seconds, int nanoseconds) {
  ts->tv_sec = seconds;
  ts->tv_nsec = nanoseconds;
  nanosleep(ts, NULL);
}

int main() {
  unsigned long long int prev_idle = 0, prev_total = 0;
  double cpu_usage;
  struct timespec ts;
  int seconds = 1;
  long int nanoseconds = 0;
  char cpu_bar[30] = "[";
  char* cpu_fill = "=====";
  char* cpu_space = "     ";

  while(1) {
    cpu_usage = calculate_cpu_usage(&prev_idle, &prev_total);

    for(int i = 0; i < 5 * (int)cpu_usage / 20; i++) {
      strcat(cpu_bar, cpu_fill);
    }
    if(strlen(cpu_bar) < 30) {
      for(int i = 0; i < 5 - (5 * (int)cpu_usage / 20); i++) {
        strcat(cpu_bar, cpu_space);
      }
    }
    strcat(cpu_bar, "]");
    printf("%s CPU usage: %.1f%%\n", cpu_bar, cpu_usage);

    memset(cpu_bar, '\0', 30);
    if(nanoseconds > 900000000) {
      seconds++;
      nanoseconds = 0;
    }
    sleep_time(&ts, seconds, nanoseconds);
    nanoseconds += 100000000;
  }

  return 0;
}