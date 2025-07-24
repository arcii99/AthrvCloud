//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: active
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  FILE* file;
  char buf[512];
  int ram_total, ram_free, ram_used;

  while (1) {
    file = fopen("/proc/meminfo", "r");
    fgets(buf, sizeof(buf), file);
    sscanf(buf, "MemTotal: %d kB", &ram_total);
    fgets(buf, sizeof(buf), file);
    sscanf(buf, "MemFree: %d kB", &ram_free);

    ram_used = ram_total - ram_free;
    printf("RAM Usage: %d kB / %d kB\n", ram_used, ram_total);

    fclose(file);
    sleep(1);
  }

  return 0;
}