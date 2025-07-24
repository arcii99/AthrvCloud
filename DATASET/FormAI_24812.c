//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024
#define CPU_USAGE_FILENAME "/proc/stat"
#define CPU_NUM_COUNTERS 10

// Function to read the CPU counters from /proc/stat file
int* read_cpu_counters()
{
  static int counters[CPU_NUM_COUNTERS];
  FILE* fp = fopen(CPU_USAGE_FILENAME, "r");
  if(fp == NULL) {
    fprintf(stderr, "Error opening %s file\n", CPU_USAGE_FILENAME);
    exit(EXIT_FAILURE);
  }

  char buffer[MAX_BUFFER_SIZE];
  fgets(buffer, MAX_BUFFER_SIZE, fp); // read the first line with CPU counters
  char* token = strtok(buffer, " ");
  token = strtok(NULL, " "); // skip the "cpu" token

  int i = 0;
  while(token && i < CPU_NUM_COUNTERS)
  {
    counters[i++] = strtol(token, NULL, 10);
    token = strtok(NULL, " ");
  }

  fclose(fp);
  return counters;
}

// Function to calculate the CPU usage percentage
float calculate_cpu_usage(int* prev_counters, int* curr_counters)
{
  int prev_total = 0, curr_total = 0;
  int prev_idle = 0, curr_idle = 0;

  for(int i = 0; i < CPU_NUM_COUNTERS; i++) {
    curr_total += curr_counters[i];
    prev_total += prev_counters[i];
    if(i == 3) // idle counter is at index 3
    {
      curr_idle = curr_counters[i];
      prev_idle = prev_counters[i];
    }
  }

  int total_diff = curr_total - prev_total;
  int idle_diff = curr_idle - prev_idle;
  float usage = 100.0 * (1.0 - ((float)idle_diff / total_diff));
  return usage;
}

int main()
{
  printf("Press Ctrl+C to stop the CPU usage monitor\n");
  int* prev_counters = read_cpu_counters();
  while(1)
  {
    sleep(1);
    int* curr_counters = read_cpu_counters();
    float usage = calculate_cpu_usage(prev_counters, curr_counters);
    printf("CPU Usage: %.2f%%\n", usage);
    memcpy(prev_counters, curr_counters, sizeof(int)*CPU_NUM_COUNTERS); // Update the previous counters
  }
  return 0;
}