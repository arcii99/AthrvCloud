//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
  struct sysinfo info;
  unsigned long long totalram = 0, freeram = 0;
  int usage = 0;

  while (1) { // monitor RAM usage continuously
    sysinfo(&info);
    totalram = info.totalram * info.mem_unit;
    freeram = info.freeram * info.mem_unit;
    usage = ((totalram - freeram) / (float)totalram) * 100;

    printf("\nTotal RAM: \t%llu MB", totalram / 1024 / 1024);
    printf("\nFree RAM: \t%llu MB", freeram / 1024 / 1024);
    printf("\nRAM usage: \t%d %%\n", usage);

    sleep(1); // wait for 1 second before checking RAM usage again
  }

  return 0;
}