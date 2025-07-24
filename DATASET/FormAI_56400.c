//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  while(1) {
    FILE* fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
      printf("Failed to fetch memory information\n");
      exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int i = 0, mem_total = 0, mem_free = 0, buffers = 0, cached = 0;
    while (fgets(buffer, sizeof(buffer), fp)) {
      if (i == 0) {
        sscanf(buffer, "MemTotal: %d", &mem_total);
        i++;
      } else if (i == 1) {
        sscanf(buffer, "MemFree: %d", &mem_free);
        i++;
      } else if (i == 4) {
        sscanf(buffer, "Buffers: %d", &buffers);
        i++;
      } else if (i == 5) {
        sscanf(buffer, "Cached: %d", &cached);
        break;
      } else {
        i++;
      }
    }

    fclose(fp);

    int mem_used = mem_total - mem_free - buffers - cached;

    printf("Total Memory: %d kB\n", mem_total);
    printf("Memory Used: %d kB\n", mem_used);
    printf("Memory Free: %d kB\n", mem_free);
    printf("Buffers: %d kB\n", buffers);
    printf("Cached: %d kB\n", cached);
    printf("\n");

    sleep(1); // waits for 1 second
  }

  return 0;
}