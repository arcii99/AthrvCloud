//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <unistd.h>

int main() {
  int i;
  int cpu_usage;
  int total_time_1;
  int total_time_2;
  int idle_time_1;
  int idle_time_2;

  printf("Welcome to the CPU Usage Monitor!\n");

  for (i = 0; i < 5; i++) {
    FILE *fp = fopen("/proc/stat", "r");
    fscanf(fp, "cpu %d %d %d %d", &total_time_1, &total_time_2, &idle_time_1, &idle_time_2);
    fclose(fp);
    usleep(1000000);

    fp = fopen("/proc/stat", "r");
    fscanf(fp, "cpu %d %d %d %d", &total_time_1, &total_time_2, &idle_time_1, &idle_time_2);
    fclose(fp);

    int total = total_time_1 + total_time_2;
    int idle = idle_time_1 + idle_time_2;

    cpu_usage = 100 * (total - idle) / total;
    printf("CPU Usage: %d%\n", cpu_usage);
  }

  printf("Thank you for using the CPU Usage Monitor!\n");

  return 0;
}