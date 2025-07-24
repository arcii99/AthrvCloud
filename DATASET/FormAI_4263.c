//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>

int main() {
  struct sysinfo info;
  long long usage, total, free;
  char buffer[1024];

  for (;;) {
    sysinfo(&info);
    total = (long long) info.totalram * info.mem_unit / (1024 * 1024);
    free = (long long) info.freeram * info.mem_unit / (1024 * 1024);
    usage = total - free;
    sprintf(buffer, "Total RAM: %lld MB, Free: %lld MB, Used: %lld MB\n", total, free, usage);
    puts(buffer);
    sleep(1);
  }

  return 0;
}