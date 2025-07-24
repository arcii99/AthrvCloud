//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
  while (1) {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {

      unsigned long long total_ram = info.totalram * info.mem_unit;
      unsigned long long free_ram = info.freeram * info.mem_unit;
      unsigned long long used_ram = total_ram - free_ram;

      printf("Total RAM: %llu bytes\n", total_ram);
      printf("Free RAM: %llu bytes\n", free_ram);
      printf("Used RAM: %llu bytes\n", used_ram);

      float used_percent = (float) used_ram / (float) total_ram * 100.0;
      printf("Used RAM Percentage: %.2f%%\n", used_percent);
    } else {
      printf("Failed to get system information.\n");
      exit(EXIT_FAILURE);
    }

    sleep(1);
  }

  return 0;
}