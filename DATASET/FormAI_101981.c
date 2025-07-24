//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: grateful
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int i = 0;
  unsigned long long int total_time, prev_total_time, idle_time, prev_idle_time;
  unsigned long long int user_time, prev_user_time, system_time, prev_system_time;
  unsigned long long int delta_total_time, delta_idle_time, delta_user_time, delta_system_time;
  FILE* file = fopen("/proc/stat", "r");
  char buffer[1024];
  fgets(buffer, sizeof(buffer), file);
  fclose(file);
  sscanf(buffer, "cpu %llu %llu %llu %llu", &prev_idle_time, &prev_user_time, &prev_system_time, &prev_total_time);

  while (i < 10) {
    file = fopen("/proc/stat", "r");
    fgets(buffer, sizeof(buffer), file);
    fclose(file);
    sscanf(buffer, "cpu %llu %llu %llu %llu", &idle_time, &user_time, &system_time, &total_time);

    delta_total_time = total_time - prev_total_time;
    delta_user_time = user_time - prev_user_time;
    delta_system_time = system_time - prev_system_time;
    delta_idle_time = idle_time - prev_idle_time;

    double usage = (delta_total_time - delta_idle_time) * 100.0 / (double) delta_total_time;

    printf("CPU usage: %.2f%%\n", usage);

    prev_total_time = total_time;
    prev_idle_time = idle_time;
    prev_user_time = user_time;
    prev_system_time = system_time;

    sleep(1);
    i++;
  }

  return 0;
}