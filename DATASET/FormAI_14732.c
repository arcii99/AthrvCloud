//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
  unsigned long long last_idle_time, last_total_time;
  float cpu_usage;

  FILE* fp = fopen("/proc/stat", "r");
  fscanf(fp, "cpu %llu %*u %llu %*u %*u %*u %*u %*u",
         &last_idle_time, &last_total_time);
  fclose(fp);

  while (1) {
    unsigned long long idle_time, total_time;
    char line[128];

    fp = fopen("/proc/stat", "r");
    fgets(line, 128, fp);
    sscanf(line, "cpu %llu %*u %llu %*u %*u %*u %*u %*u", &idle_time, &total_time);
    fclose(fp);

    float idle_time_delta = idle_time - last_idle_time;
    float total_time_delta = total_time - last_total_time;
    cpu_usage = 100.0 * (1.0 - ((float)idle_time_delta / (float)total_time_delta));

    printf("CPU Usage: %.2f%%\n", cpu_usage);

    last_idle_time = idle_time;
    last_total_time = total_time;

    sleep(1);
  }

  return 0;
}