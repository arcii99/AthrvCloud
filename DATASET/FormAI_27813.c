//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CPU 4
#define MAX_LINE_LENGTH 256

struct CPU_stats {
  long int user_mode;
  long int nice_mode;
  long int system_mode;
  long int idle_mode;
  long int iowait_mode;
};

int main() {
  char filename[] = "/proc/stat";
  FILE* fp;
  char line[MAX_LINE_LENGTH];
  long int total_time[MAX_CPU];
  long int prev_total_time[MAX_CPU];
  long int idle_time[MAX_CPU];
  long int prev_idle_time[MAX_CPU];
  float cpu_percent[MAX_CPU];
  int i = 0;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  // Read initial CPU stats to calculate usage percentage
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && i < MAX_CPU) {
    if (strncmp(line, "cpu", 3) == 0) {
      char* token = strtok(line, " ");
      int j = 0;
      long int temp_time = 0;

      while (token != NULL && j <= 9) {
        token = strtok(NULL, " ");

        if (j == 0) {
          // Skip first token, which is "cpu"
        } else {
          temp_time += strtol(token, NULL, 10);
        }

        j++;
      }

      total_time[i] = temp_time;
      idle_time[i] = strtol(token, NULL, 10);
      prev_total_time[i] = total_time[i];
      prev_idle_time[i] = idle_time[i];

      i++;
    }
  }

  fclose(fp);

  while (1) {
    fp = fopen(filename, "r");
    if (fp == NULL) {
      printf("Error opening file %s\n", filename);
      exit(1);
    }

    // Read current CPU stats to calculate usage percentage
    i = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && i < MAX_CPU) {
      if (strncmp(line, "cpu", 3) == 0) {
        char* token = strtok(line, " ");
        int j = 0;
        long int temp_time = 0;

        while (token != NULL && j <= 9) {
          token = strtok(NULL, " ");

          if (j == 0) {
            // Skip first token, which is "cpu"
          } else {
            temp_time += strtol(token, NULL, 10);
          }

          j++;
        }

        total_time[i] = temp_time;
        idle_time[i] = strtol(token, NULL, 10);

        // Calculate usage percentage since last check
        long int total_diff = total_time[i] - prev_total_time[i];
        long int idle_diff = idle_time[i] - prev_idle_time[i];
        cpu_percent[i] = (1 - (float)idle_diff/total_diff) * 100;

        prev_total_time[i] = total_time[i];
        prev_idle_time[i] = idle_time[i];

        i++;
      }
    }

    fclose(fp);

    printf("CPU Usage\n");
    printf("---------\n");
    for (i = 0; i < MAX_CPU; i++) {
      printf("Core %d: %.2f%%\n", i, cpu_percent[i]);
    }

    printf("\n");

    // Sleep for 1 second before checking again
    sleep(1);

  }

  return 0;
}