//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int idle_ticks, prev_idle_ticks = 0;
  int system_ticks, prev_system_ticks = 0;
  int user_ticks, prev_user_ticks = 0;
  int total_ticks, prev_total_ticks = 0;
  double cpu_percentage;

  while(1) {
    FILE* fp = fopen("/proc/stat", "r");
    fscanf(fp, "cpu %d %d %d %d", &user_ticks, &system_ticks, &idle_ticks, &total_ticks);
    fclose(fp);

    if(prev_total_ticks != 0) {
      double total_ticks_since_last_read = (total_ticks - prev_total_ticks) * 1.0;
      double idle_ticks_since_last_read = (idle_ticks - prev_idle_ticks) * 1.0;
      double system_ticks_since_last_read = (system_ticks - prev_system_ticks) * 1.0;

      cpu_percentage = (total_ticks_since_last_read - idle_ticks_since_last_read) / total_ticks_since_last_read * 100.0;
      printf("CPU Usage: %.2f%%\n", cpu_percentage);
    }

    prev_idle_ticks = idle_ticks;
    prev_system_ticks = system_ticks;
    prev_user_ticks = user_ticks;
    prev_total_ticks = total_ticks;

    sleep(1);
  }

  return 0;
}