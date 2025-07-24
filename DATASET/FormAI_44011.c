//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int cpu_usage;
  printf("Welcome to the Mind-Bending CPU Usage Monitor!\n");

  while(1) {
    FILE* fp = fopen("/proc/stat", "r");
    if(fp == NULL) {
      printf("Unable to open /proc/stat. Exiting program.\n");
      exit(1);
    }

    int idle_time1, user_time1, nice_time1, system_time1, idle_time2, user_time2, nice_time2, system_time2;
    fscanf(fp, "cpu %d %d %d %d %d %d %d %d", &user_time1, &nice_time1, &system_time1, &idle_time1, &user_time2, &nice_time2, &system_time2, &idle_time2);
    fclose(fp);

    int total_time1 = user_time1 + nice_time1 + system_time1 + idle_time1;
    int total_time2 = user_time2 + nice_time2 + system_time2 + idle_time2;
    int total_time_diff = total_time2 - total_time1;
    int idle_time_diff = idle_time2 - idle_time1;
    cpu_usage = 100 * (total_time_diff - idle_time_diff) / total_time_diff;

    if(cpu_usage >= 95) {
      printf("CPU Usage is at %d%%! YOU ARE ENTERING THE MIND-BENDING ZONE!!!\n", cpu_usage);
    } else if(cpu_usage >= 80) {
      printf("The CPU is working hard at %d%%... better take a break soon.\n", cpu_usage);
    } else if(cpu_usage >= 60) {
      printf("The CPU is at %d%%... not too bad, but maybe keep an eye on it.\n", cpu_usage);
    } else {
      printf("The CPU is at %d%%... nice and relaxed.\n", cpu_usage);
    }

   sleep(1);
  }
  return 0;
}