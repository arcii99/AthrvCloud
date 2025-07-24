//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
  struct sysinfo sys_info;

  while (1) {
    if(sysinfo(&sys_info) != 0) {
      fprintf(stderr, "Error getting system info.\n");
    }

    long total_ram = sys_info.totalram / 1024L;
    long free_ram = sys_info.freeram / 1024L;
    long used_ram = total_ram - free_ram;
    double mem_used_percent = ((double)used_ram / (double)total_ram) * 100.0;

    printf("RAM Usage: %ld MB (%.2f%%)\n", used_ram, mem_used_percent);

    sleep(1);
  }

  return 0;
}