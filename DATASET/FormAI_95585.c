//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  long double total_mem, free_mem, used_mem, buffered_mem, cached_mem;
  char* line = NULL;
  FILE* fp = fopen("/proc/meminfo", "r");

  if (fp == NULL) {
    printf("Error: Unable to open /proc/meminfo\n");
    return 1;
  }

  while (getline(&line, NULL, fp) != -1) {
    if (strstr(line, "MemTotal") != NULL) {
      sscanf(line, "MemTotal: %Lf kB", &total_mem);
    } else if (strstr(line, "MemFree") != NULL) {
      sscanf(line, "MemFree: %Lf kB", &free_mem);
    } else if (strstr(line, "Buffers") != NULL) {
      sscanf(line, "Buffers: %Lf kB", &buffered_mem);
    } else if (strstr(line, "Cached") != NULL) {
      sscanf(line, "Cached: %Lf kB", &cached_mem);
    }
  }

  fclose(fp);
  free(line);

  used_mem = total_mem - free_mem - buffered_mem - cached_mem;

  printf("Total memory available: %.2Lf MB\n", total_mem/1024);
  printf("Memory in use: %.2Lf MB\n", used_mem/1024);
  printf("Memory free: %.2Lf MB\n", free_mem/1024);

  return 0;
}