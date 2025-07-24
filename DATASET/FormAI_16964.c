//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {
  while(1) {
    struct sysinfo info;
    sysinfo(&info);
    unsigned long long total_mem = info.totalram * info.mem_unit;
    unsigned long long free_mem = info.freeram * info.mem_unit;
    unsigned long long used_mem = total_mem - free_mem;
    unsigned int ram_percentage = (used_mem * 100) / total_mem;
    printf("\033c"); // Clear console
    printf("**** C RAM Usage Monitor ****\n");
    printf("\nTotal Memory:\t%llu bytes", total_mem);
    printf("\nFree Memory:\t%llu bytes", free_mem);
    printf("\nUsed Memory:\t%llu bytes", used_mem);
    printf("\nRAM Usage:\t%u%%", ram_percentage);
    printf("\n\n");
    sleep(1);
  }
  return 0;
}